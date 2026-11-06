
void minimumBribes(vector<int> q) {
    int total = 0;
    int length = q.size();

    for (int pos = 0; pos < length; pos++) {
        int person = q[pos];

        if (person > pos + 3) {
            cout << "Too chaotic" << endl;
            return;
        }

        int start = person - 2;

        if (start < 0) {
            start = 0;
        }

        for (int k = start; k < pos; k++) {
            if (q[k] > person) {
                total += 1;
            }
        }
    }

    cout << total << endl;
}
