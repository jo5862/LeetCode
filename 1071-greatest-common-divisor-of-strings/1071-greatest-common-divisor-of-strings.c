int gcd(int a, int b) {
    while (b != 0) {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

char* gcdOfStrings(char* str1, char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int gcdLength = gcd(len1, len2);

    // str1의 첫 gcdLength 길이의 부분 문자열을 얻습니다.
    char *candidate = strndup(str1, gcdLength);

    // str1이 candidate로 나누어지는지 확인
    for (int i = 0; i < len1; i += gcdLength) {
        if (strncmp(str1 + i, candidate, gcdLength) != 0) {
            return "";  // 나누어지지 않으면 빈 문자열을 반환
        }
    }

    // str2가 candidate로 나누어지는지 확인
    for (int i = 0; i < len2; i += gcdLength) {
        if (strncmp(str2 + i, candidate, gcdLength) != 0) {
            return "";  // 나누어지지 않으면 빈 문자열을 반환
        }
    }

    return candidate;  // 두 문자열을 모두 나누어주는 가장 큰 문자열 반환
}
