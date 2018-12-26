#ifndef Z_HELLO
#define Z_HELLO

void* func_80057030(void* copyto, const void* copyfrom, int n)
/* memcpy? */
{
    char* a = (char*) copyto;
    char* b = (char*) copyfrom;
    
    while (n > 0)
    {
        *a = *b;
        a++;
        b++;
        n--;
    }
    return copyto;
}

void* func_80057060(void* copyto, int val, int bytes)
/* memset? */
{
    char* v0 = (char*) copyto;
    int v;
    
    for (v = bytes; v > 0; v--)
        *v0++ = val;
    
    return copyto;
}


#endif
