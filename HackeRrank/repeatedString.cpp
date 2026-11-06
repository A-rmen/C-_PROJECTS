
long repeatedString(string s, long n) {
    long long length = s.length();
    long long letters = 0;

    for (char ch : s) {
        if (ch == 'a') {
            letters++;
        }
    }

    long long repeats = n / length;
    long long remaining = n % length;
    long long result = repeats * letters;

    for (int i = 0; i < remaining; i++) {
        if (s[i] == 'a') {
            result++;
        }
    }

    return result;
}
