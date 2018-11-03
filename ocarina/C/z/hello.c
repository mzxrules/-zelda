void* func_80057030(char* copyto, char* copyfrom, int bytes)
{
    char* a = copyto;
    char* b = copyfrom;
    
    while (bytes > 0)
    {
        a[0] = b[0];
        a++;
        b++;
        bytes--;
    }
    return copyto;
}
