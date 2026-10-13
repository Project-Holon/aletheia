/*
 * function: func_021E6840
 * address: 0x021E6840
 * packet: pkt_ov093_021E6840
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: Callback kind 10 is reused as the multiplier, then decreased by 11;
 * this retains the live constant and reproduces the spill frame and muls.
 * symbols:
 *   BTL_EVENT_GetVar 0x021D775C thumb ov093
 *   func_021E6908 0x021E6908 thumb ov093
 *   func_021C7CF4 0x021C7CF4 thumb ov093
 *   BTL_POKEPARAM_IsFainted 0x021D5B68 thumb ov093
 *   BTL_POKEPARAM_FindMoveSlot 0x021D5778 thumb ov093
 *   func_021C88A4 0x021C88A4 thumb ov093
 *   BTL_POKEPARAM_GetMovePPChecked 0x021D5584 thumb ov093
 *   func_021C8838 0x021C8838 thumb ov093
 *   func_021C8860 0x021C8860 thumb ov093
 *   func_021C88C8 0x021C88C8 thumb ov093
 *   BTL_EVENT_RemoveFactor 0x021D7040 thumb ov093
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int BTL_EVENT_GetVar(int);
extern int func_021E6908(u16);
struct Node;
struct UtilWork;
extern void *func_021C7CF4(int *p, int i);
extern int BTL_POKEPARAM_IsFainted(void *);
extern u8 BTL_POKEPARAM_FindMoveSlot(struct UtilWork *p, u16 id);
extern void *func_021C88A4(char *p, int a, int b);
extern u8 BTL_POKEPARAM_GetMovePPChecked(struct UtilWork *p, u32 i);
extern void func_021C8838(void *, int, int);
struct S;
extern void func_021C8860(struct S *, u32);
extern void func_021C88C8(void *, void *);
extern void BTL_EVENT_RemoveFactor(struct Node *n);
void func_021E6840(void *x, void *a, int c)
{
    u8 k;
    void *m;
    u16 id;
    int i;
    u8 *p;
    int multiplier;
    if (c == BTL_EVENT_GetVar(4)) {
        if (func_021E6908((u16)BTL_EVENT_GetVar(18)) == 0) {
            if (BTL_POKEPARAM_IsFainted(func_021C7CF4(a, c)) != 0) {
                k = BTL_EVENT_GetVar(3);
                m = func_021C7CF4(a, k);
                id = BTL_EVENT_GetVar(20);
                i = BTL_POKEPARAM_FindMoveSlot(m, id);
                if (i != 4) {
                    multiplier = 10;
                    p = func_021C88A4(a, multiplier, c);
                    p[5] = k;
                    p[6] = i;
                    multiplier -= 11;
                    p[4] = BTL_POKEPARAM_GetMovePPChecked(m, (u8)i) * multiplier;
                    p[7] |= 2;
                    func_021C8838(p + 8, 2, 0x27b);
                    func_021C8860((struct S *)(p + 8), k);
                    func_021C8860((struct S *)(p + 8), id);
                    func_021C88C8(a, p);
                }
                BTL_EVENT_RemoveFactor(x);
            }
        }
    }
}
