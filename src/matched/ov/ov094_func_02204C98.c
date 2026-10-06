/*
 * function: func_02204C98
 * address:  0x02204C98
 * packet:   pkt_ov094_02204C98
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT
 */
typedef unsigned int   u32;
struct StrObj;
extern u32 func_0201D304(struct StrObj *s, u32 a, u32 b);
extern int func_0207C994(int n, int d);

void func_02204C98(struct StrObj *a, int b, int *outn, int *outq)
{
    int n = func_0201D304(a, b, 0);
    int q = n / 8;
    if (func_0207C994(n, 8) != 0)
        q++;
    *outn = n;
    *outq = q;
}
