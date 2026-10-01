/*
 * function: func_021F8518
 * address: 0x021F8518
 * packet: pkt_ov185_021F8518
 * region: ov185
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   ov112_id 0x00000070 data
 *   func_021F8D5C 0x021F8D5C thumb ov185
 *   func_021F8E60 0x021F8E60 thumb ov185
 *   func_021F8EE8 0x021F8EE8 thumb ov185
 *   func_021F8F58 0x021F8F58 thumb ov185
 *   func_021F8FB0 0x021F8FB0 thumb ov185
 *   func_021FD714 0x021FD714 thumb ov186
 *   func_021FC0C8 0x021FC0C8 thumb ov186
 *   func_021FD820 0x021FD820 thumb ov186
 *   func_02025588 0x02025588 thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_020315D4 0x020315D4 arm
 *   func_02034A5C 0x02034A5C arm
 */
extern void func_021F8D5C(char *,char *);
extern void func_021F8E60(char *,char *);
extern void func_021F8EE8(char *,char *);
extern void func_021F8F58(char *,char *);
extern void func_021F8FB0(char *,char *);
extern void func_021FD714(int);
extern void func_021FC0C8(int,int);
extern void func_021FD820(char *);
extern void func_02025588(int);
extern void func_0201C4C0(int);
extern void func_020315D4(int);
extern void func_02034A5C(int);
extern char ov112_id[];
int func_021F8518(int obj,int b,char *q,char *p)
{
    int i;
    func_021F8D5C(p,q);
    func_021F8E60(p,q);
    func_021F8EE8(p,q);
    func_021F8F58(p,q);
    func_021F8FB0(p,q);
    func_021FD714(*(int *)(p+36));
    func_021F8F58(p,q);
    func_021FC0C8(*(int *)(q+12),6);
    for (i=0;i<2;i++) func_021FD820(*(char **)(p+i*4+56));
    func_02025588(*(int *)(p+40));
    func_0201C4C0(*(int *)(p+44));
    func_020315D4(obj);
    func_02034A5C((int)ov112_id);
    return 1;
}
