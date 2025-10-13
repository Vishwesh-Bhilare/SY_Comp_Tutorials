#include <bits/stdc++.h>
using namespace std;

// ========================= Base Class =========================
class Record {
protected:
    int id;
    string title;
public:
    Record(int id, string title) : id(id), title(std::move(title)) {}
    virtual void display() const = 0; // pure virtual for polymorphism
};

// ========================= Task =========================
class Task : public Record {
    bool done;
    int hoursEstimated, hoursSpent;
public:
    Task(int id, const string &title, int hoursEstimated = 0)
        : Record(id, title), done(false),
          hoursEstimated(hoursEstimated), hoursSpent(0) {}

    void logHours(int h) { hoursSpent += h; }
    void markDone() { done = true; }
    bool isDone() const { return done; }

    void display() const override {
        cout << "[Task] #" << id << ": " << title
             << " | Done: " << (done ? "Yes" : "No")
             << " | Est: " << hoursEstimated << "h"
             << " | Spent: " << hoursSpent << "h\n";
    }
};

// ========================= Invoice =========================
class Invoice : public Record {
    double amount;
    bool paid;
public:
    Invoice(int id, const string &title, double amount, bool paid = false)
        : Record(id, title), amount(amount), paid(paid) {}

    void markPaid() { paid = true; }
    bool isPaid() const { return paid; }
    double getAmount() const { return amount; }

    void display() const override {
        cout << "[Invoice] #" << id << ": " << title
             << " | Amount: Rs." << fixed << setprecision(2) << amount
             << " | Paid: " << (paid ? "Yes" : "No") << "\n";
    }
};

// ========================= Project =========================
class Project {
    int id;
    string name, client, status;
    vector<Task> tasks;
    vector<Invoice> invoices;
public:
    Project(int id, string name, string client, string status = "Active")
        : id(id), name(std::move(name)), client(std::move(client)), status(std::move(status)) {}

    void addTask(const string &title, int estHours = 0) {
        tasks.emplace_back(tasks.size() + 1, title, estHours);
    }

    void addInvoice(const string &title, double amount, bool paid = false) {
        invoices.emplace_back(invoices.size() + 1, title, amount, paid);
    }

    void showSummary() const {
        cout << "\n=== Project #" << id << ": " << name
             << " | Client: " << client
             << " | Status: " << status << " ===\n";
        for (const auto &t : tasks) t.display();
        for (const auto &inv : invoices) inv.display();
    }

    int getId() const { return id; }
    string getName() const { return name; }
    string getStatus() const { return status; }

    int totalTasks() const { return tasks.size(); }

    int doneTasks() const {
        int count = 0;
        for (const auto &t : tasks) if (t.isDone()) count++;
        return count;
    }

    double totalInvoiceAmount(bool onlyPaid) const {
        double sum = 0;
        for (const auto &inv : invoices)
            if (!onlyPaid || inv.isPaid()) sum += inv.getAmount();
        return sum;
    }
};

// ========================= Dashboard =========================
class Dashboard {
    static void bar(int value, int maxVal, int width = 20, char c = '#') {
        int filled = (maxVal == 0) ? 0 : (value * width / maxVal);
        cout << "[";
        for (int i = 0; i < width; i++) cout << (i < filled ? c : ' ');
        cout << "] " << value << "/" << maxVal << "\n";
    }
public:
    static void showOverview(const vector<Project> &projects) {
        cout << "\n========== DASHBOARD ==========\n";
        cout << "Total projects: " << projects.size() << "\n\n";

        map<string, int> statusCount;
        for (const auto &p : projects) statusCount[p.getStatus()]++;

        cout << "Projects by status:\n";
        for (auto &[status, count] : statusCount) {
            cout << "  " << status << " ";
            bar(count, projects.size(), 30, '=');
        }
        cout << "\n";

        for (const auto &p : projects) {
            int total = p.totalTasks();
            int done = p.doneTasks();
            cout << "Project #" << p.getId() << " (" << p.getName() << ") - Tasks: ";
            bar(done, total == 0 ? 1 : total, 25, '#');

            double paid = p.totalInvoiceAmount(true);
            double totalInv = p.totalInvoiceAmount(false);
            cout << "   Invoices Paid: $" << paid << " / $" << totalInv << "\n\n";
        }

        cout << "===============================\n";
    }
};

// ========================= Menu Helpers =========================
void showMenu() {
    cout << "\n--- Freelancer Project Tracker ---\n"
         << "1. Create Project\n"
         << "2. Add Task to Project\n"
         << "3. Add Invoice to Project\n"
         << "4. Show Dashboard\n"
         << "5. Exit\n"
         << "Choose: ";
}

// ========================= Main =========================
int main() {
    vector<Project> projects;
    int choice;

    while (true) {
        showMenu();
        if (!(cin >> choice)) break;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 1) {
            string name, client;
            cout << "Enter project name: ";
            getline(cin, name);
            cout << "Enter client: ";
            getline(cin, client);
            projects.emplace_back(projects.size() + 1, name, client);
            cout << "✅ Project created.\n";

        } else if (choice == 2) {
            if (projects.empty()) { cout << "⚠️ No projects yet.\n"; continue; }
            int pid, est; string title;
            cout << "Enter project ID: "; cin >> pid; cin.ignore();
            cout << "Task title: "; getline(cin, title);
            cout << "Estimated hours: "; cin >> est; cin.ignore();

            if (pid > 0 && pid <= (int)projects.size())
                projects[pid - 1].addTask(title, est);
            else cout << "❌ Invalid project ID.\n";

        } else if (choice == 3) {
            if (projects.empty()) { cout << "⚠️ No projects yet.\n"; continue; }
            int pid; string title; double amt;
            cout << "Enter project ID: "; cin >> pid; cin.ignore();
            cout << "Invoice title: "; getline(cin, title);
            cout << "Amount: "; cin >> amt; cin.ignore();

            if (pid > 0 && pid <= (int)projects.size())
                projects[pid - 1].addInvoice(title, amt);
            else cout << "❌ Invalid project ID.\n";

        } else if (choice == 4) {
            Dashboard::showOverview(projects);

        } else if (choice == 5) {
            cout << "Exiting... Goodbye!\n";
            break;

        } else {
            cout << "❌ Invalid option. Try again.\n";
        }
    }
    return 0;
}
