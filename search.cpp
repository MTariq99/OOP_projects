#include <stdio.h>
int main()
{
    char c_to_search[5] = "asdf";

    char text[68] = "hello my name is \0 there is asdf some other string behind it \n\0 ";

    int pos_search = 0;
    int pos_text = 0;
    int len_search = 4;
    int len_text = 67;
    for (pos_text = 0; pos_text < len_text - len_search; ++pos_text)
    {
        if (text[pos_text] == c_to_search[pos_search])
        {
            ++pos_search;
            if (pos_search == len_search)
            {
                // match
                printf("match from %d to %d\n", pos_text - len_search, pos_text);
                return 0;
            }
        }
        else
        {
            pos_text -= pos_search;
            pos_search = 0;
        }
    }
    // no match
    printf("no match\n");
    return 0;
}