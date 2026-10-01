/*
 * function: func_021D9E98
 * address: 0x021D9E98
 * packet: pkt_ov129_021D9E98
 * region: ov129
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0204B404 0x0204B404 arm
 *   func_0204B8C4 0x0204B8C4 arm
 */
typedef unsigned short u16;
typedef struct { u16 x,y; } Pair;
extern void func_0204B404(int,void *,int);
extern void func_0204B8C4(int,int);
void func_021D9E98(char *p,int i)
{
    Pair s;
    unsigned char *q = (unsigned char *)p + (i+12)*4;
    s.x = (q[0x29a] + q[0x29b])/2;
    s.y = (q[0x298] + q[0x299])/2;
    func_0204B404(*(int *)(p+0x1b0),&s,0);
    func_0204B8C4(*(int *)(p+0x1b0),0);
}
