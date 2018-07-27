unsigned long long __umoddi3(unsigned long long num, unsigned long long den)
 {
   unsigned long long v;
 
   (void) __udivmoddi4(num, den, &v);
   return v;
 }