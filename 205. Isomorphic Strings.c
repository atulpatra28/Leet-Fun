bool isIsomorphic(char* s, char* t) {
    int s_map[256] = {0}; // Assuming ASCII characters
    int t_map[256] = {0}; // Assuming ASCII characters

    int len = strlen(s);
    if (len != strlen(t))
        return false;

    for (int i = 0; i < len; i++) {
        // Check if the current mapping is consistent
        if (s_map[s[i]] != 0 && s_map[s[i]] != t[i])
            return false;
        if (t_map[t[i]] != 0 && t_map[t[i]] != s[i])
            return false;

        // Update the mappings
        s_map[s[i]] = t[i];
        t_map[t[i]] = s[i];
    }

    return true;
}