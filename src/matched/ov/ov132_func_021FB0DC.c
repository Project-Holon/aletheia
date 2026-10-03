/*
 * function: func_021FB0DC
 * address: 0x021FB0DC
 * packet: pkt_ov132_021FB0DC
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021FAE1C 0x021FAE1C thumb ov132
 *   func_021F9E00 0x021F9E00 thumb ov132
 *   func_021FADF8 0x021FADF8 thumb ov132
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern int func_021FAE1C(char *, int *);
extern void func_021F9E00(void *, u16);
extern void func_021FADF8(char *, char *);
void func_021FB0DC(void *unused, char *p)
{
    int v;
    int done = func_021FAE1C(p, &v);
    func_021F9E00(*(void **)p, v);
    if (done == 1) func_021FADF8(*(char **)(p + 0x10), *(char **)(p + 0x14));
}
