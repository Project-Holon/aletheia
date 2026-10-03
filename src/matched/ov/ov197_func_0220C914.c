/*
 * function: func_0220C914
 * address: 0x0220C914
 * packet: pkt_ov197_0220C914
 * region: ov197
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0220D3B0 0x0220D3B0 thumb ov197
 *   func_0220BF40 0x0220BF40 thumb ov197
 *   func_0220B980 0x0220B980 thumb ov197
 *   func_020310C4 0x020310C4 arm
 *   func_0202CD94 0x0202CD94 thumb
 *   d_0220DF40 0x0220DF40 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
struct Tcbl;
struct WinMgr;
extern int (*const d_0220DF40[])(char *);
extern int func_0220D3B0(void *, char *);
extern void func_0220BF40(char *);
extern int func_0220B980(char *);
extern void func_020310C4(struct Tcbl *);
extern void func_0202CD94(struct WinMgr *mgr);
void func_0220C914(void *task, char *p)
{
    if (*(int *)(*(char **)p + 0x24) == 1) {
        *(u16 *)(*(char **)p + 0x16) = 0;
        *(u8 *)(*(char **)p + 0x18) = 0;
        *(u8 *)(p + 0x530) = 20;
    }
    if (*(u8 *)(p + 0x530) != 20) *(u8 *)(p + 0x530) = d_0220DF40[*(u8 *)(p + 0x530)](p);
    if (*(u8 *)(p + 0x530) == 20 && func_0220D3B0(task, p) == 1) return;
    func_020310C4(*(struct Tcbl **)(p + 4));
    func_0220BF40(p);
    func_0202CD94(*(struct WinMgr **)(p + 0x520));
    func_0220B980(p);
}
