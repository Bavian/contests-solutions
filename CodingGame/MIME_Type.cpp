#include <iostream>
#include <algorithm>
#include <cstring>

// CONSTANTS
const int N_MIN = 0,
          N_MAX = 10000,
          Q_MIN = 0,
          Q_MAX = 10000,
          FILE_EXTENSION_MAX_LENGTH = 10,
          MIME_TYPE_MAX_LENGTH = 50,
          FILE_NAME_MAX_LENGTH = 256;
char UNKNOWN[8] = "UNKNOWN";

// VARIABLES
int n, q;
char **extensions, **mimes, **files, **answers;

// MAIN CODE

void toLowerCase(char* str) {
    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        if ('A' <= str[i] && str[i] <= 'Z') {
            str[i] = str[i] - 'A' + 'a';
        }
    }
}

void in() {
    std::cin >> n >> q; std::cin.ignore();

    extensions = new char*[n];
    mimes = new char*[n];
    files = new char*[q];
    answers = new char*[q];

    for (int i = 0; i < n; i++) {
        extensions[i] = new char[FILE_EXTENSION_MAX_LENGTH];
        mimes[i] = new char[MIME_TYPE_MAX_LENGTH];
        std::cin >> extensions[i] >> mimes[i];
        std::reverse(extensions[i], extensions[i] + strlen(extensions[i]));
        toLowerCase(extensions[i]);
    }

    for (int i = 0; i < q; i++) {
        files[i] = new char[FILE_NAME_MAX_LENGTH];
        std::cin >> files[i];
        std::reverse(files[i], files[i] + strlen(files[i]));
        toLowerCase(files[i]);
    }
}

bool isType(char* file, char* type) {
    bool result = true;
    int fileLength = strlen(file);
    int typeLength = strlen(type);
    if (fileLength < typeLength + 1) {
        return false;
    }

    for (int i = 0; i < typeLength; i++) {
        result = result && file[i] == type[i];
    }
    return result && file[typeLength] == '.';
}

void solution() {
    int mimesIndices[n];
    for (int i = 0; i < n; i++) {
        mimesIndices[i] = i;
    }
    std::sort(mimesIndices, mimesIndices + n, [](int i, int j) {
        return strcmp(extensions[i], extensions[j]) < 0;
    });

    int filesIndices[q];
    for (int i = 0; i < q; i++) {
        filesIndices[i] = i;
    }
    std::sort(filesIndices, filesIndices + q, [](int i, int j) {
        return strcmp(files[i], files[j]) < 0;
    });

    /*  
    for (int i = 0; i < n; i++) {
        std::cout << i << ' ' << mimesIndices[i] << ' ' << extensions[mimesIndices[i]] << '\n';
    }
    std::cout << '\n';
    for (int i = 0; i < q; i++) {
        std::cout << i << ' ' << filesIndices[i] << ' ' << files[filesIndices[i]] << '\n';
    }
    std::cout << '\n';
    */

    int j = 0;
    for (int i = 0; i < q; i++) {
        if (j >= n) {
            answers[filesIndices[i]] = UNKNOWN;
            //std::cout << filesIndices[i] << " j1\n";
            continue;
        }

        if (strcmp(files[filesIndices[i]], extensions[mimesIndices[j]]) <= 0) {
            answers[filesIndices[i]] = UNKNOWN;
            //std::cout << filesIndices[i] << " " << mimesIndices[j] << " strcmp1\n";
            continue;
        }

        bool skip = false;
        while (!isType(files[filesIndices[i]], extensions[mimesIndices[j]])) {
            j++;
            if (j >= n) {
                answers[filesIndices[i]] = UNKNOWN;
                //std::cout << filesIndices[i] << " j2\n";
                skip = true;
                break;
            }
            if (strcmp(files[filesIndices[i]], extensions[mimesIndices[j]]) < 0) {
                answers[filesIndices[i]] = UNKNOWN;
                //std::cout << filesIndices[i] << " strcmp2\n";
                skip = true;
                break;
            }
        }

        if (skip) {
            //std::cout << filesIndices[i] << " j3\n";
            continue;
        }

        //std::cout << filesIndices[i] << "success\n";
        answers[filesIndices[i]] = mimes[mimesIndices[j]];
    }
}

void out() {
    for (int i = 0; i < q; i++) {
        std::cout << answers[i] << '\n';
    }
}

int main() {
    in();
    solution();
    out();
    return 0;
}

