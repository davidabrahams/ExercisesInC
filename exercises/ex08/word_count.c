
#include <stdio.h>
#include <stdlib.h>
#include <glib.h>


int main() {
  char book[] = "book.txt";
  gchar *contents;
  gsize size;
  GHashTable *wordToCount = g_hash_table_new(g_str_hash, g_str_equal);

  if (g_file_get_contents (book, &contents, &size, NULL)) {
    // replace all whitespace with spaces
    g_strdelimit(contents, " \n\t", ' ');
    gchar **words = g_strsplit(contents, " ", -1);
    int i = 0;
    while (1) {
      gchar *word = words[i];
      if (!word) break;
      if (!g_hash_table_contains(wordToCount, word)) {
        // g_hash_table_insert(wordToCount, word, "poop");
        g_hash_table_insert(wordToCount, word, GINT_TO_POINTER(0));
      }
      int incr = GPOINTER_TO_INT(g_hash_table_lookup(wordToCount, word)) + 1;
      g_hash_table_insert(wordToCount, word, GINT_TO_POINTER(incr));
      i++;
    }
    // definitely inefficient, but, find the max key, remove it and print, then
    // repeat
    //
    guint length = g_hash_table_size(wordToCount);
    gchar** keys;
    while (length > 0) {
      keys = (const gchar **) g_hash_table_get_keys_as_array(wordToCount, &length);

    }
    g_free(contents);
    g_free(keys);
  }
  return 0;
}
