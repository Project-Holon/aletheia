/*
 * function: func_021D8270
 * address: 0x021D8270
 * packet: pkt_ov123_021D8270
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D6EE0 0x021D6EE0 thumb ov123
 *   func_021D584C 0x021D584C thumb ov123
 *   func_021D8244 0x021D8244 thumb ov123
 *   func_021D8154 0x021D8154 thumb ov123
 *   func_021D706C 0x021D706C thumb ov123
 */
typedef unsigned int   u32;
typedef unsigned char  u8;
struct TaskMenu;
extern void func_020061E4(u32 a);
extern u32 func_020279E8(struct TaskMenu *m);
extern u8 func_02027A04(const u8 *p);
extern int func_020076D0(void *, void *, void *);
extern void func_021D6EE0(char *, int, int);
extern void func_021D584C(char *);
extern void func_02027858(struct TaskMenu *m);
extern void func_021D8244(char *p);
extern void func_021D8154(char *p);
extern void func_021D706C(char *p);
void func_021D8270(char *p)
{
    if (*(int *)(p + 0x64) % 110 == 0) func_020061E4(0x659);
    (*(int *)(p + 0x64))++;
    if (func_020279E8(*(void **)(p + 0x1c))) {
        if (func_02027A04(*(void **)(p + 0x1c)) == 0) {
            if (func_020076D0(*(void **)(p + 0x24), p + 0x48, p + 0x4c) == 0)
                func_021D6EE0(p, (int)func_021D8244, 0x60f);
            else
                func_021D6EE0(p, (int)func_021D8154, 0x612);
        } else {
            func_021D6EE0(p, (int)func_021D706C, 0x616);
        }
        func_021D584C(*(char **)(p + 0x18));
        func_02027858(*(void **)(p + 0x1c));
        *(unsigned short *)0x04001050 = 0;
        *(void **)(p + 0x1c) = 0;
    }
}
