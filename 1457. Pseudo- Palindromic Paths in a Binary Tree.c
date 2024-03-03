/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int pseudoPalindromicPaths(struct TreeNode* root) {
    int count = 0; // Counter for valid paths

    // Helper function to recursively explore the tree
    void dfs(struct TreeNode* node, int freq[10]) {
        if (node == NULL) {
            return; // Base case: null node
        }

        // Increment frequency of current node's value
        freq[node->val]++;

        // Check if the path from root to current node is pseudo-palindromic
        int oddCount = 0;
        for (int i = 0; i < 10; i++) {
            if (freq[i] % 2 != 0) {
                oddCount++;
            }
            // Early exit if more than one odd frequency is found
            if (oddCount > 1) {
                break;
            }
        }

        // If path is pseudo-palindromic and at a leaf node, increment count
        if (oddCount <= 1 && node->left == NULL && node->right == NULL) {
            count++;
        }

        // Explore left and right subtrees recursively
        dfs(node->left, freq);
        dfs(node->right, freq);

        // Decrement frequency after exploring subtree
        freq[node->val]--;
    }

    // Create a frequency array for digit counts
    int freq[10] = {0};

    // Start the exploration from the root node
    dfs(root, freq);

    return count;
}
