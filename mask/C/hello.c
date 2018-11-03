

extern void func_mm_80089630(void* a, int b);

void func_mm_80080150(void* a, void* b)
{
    if (b <= a)
        return;
    
    func_mm_80089630(a, ((char *)b) - ((char *)a));
}