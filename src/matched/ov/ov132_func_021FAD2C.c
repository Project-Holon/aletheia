/*
 * function: func_021FAD2C
 * address: 0x021FAD2C
 * packet: pkt_ov132_021FAD2C
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * note: follower 021FAD7C is separately filed under pkt_ov132_021FAD7C.
 * symbols:
 *   func_02011298 0x02011298 thumb
 *   func_02011290 0x02011290 thumb
 *   func_02011264 0x02011264 thumb
 *   func_020307B0 0x020307B0 arm
 */
typedef unsigned short u16;
struct ScriptVm;
extern int func_02011298(struct ScriptVm *vm);
extern void func_02011290(struct ScriptVm *vm);
extern void func_02011264(void *);
extern void func_020307B0(void *);
int func_021FAD2C(void *unused, char *p)
{
    if (*(u16 *)(p + 0x14) != 0) (*(u16 *)(p + 0x14))--;
    if (*(u16 *)(p + 0x14) == 0 && !(*(u16 *)(p + 0x16) & 4)) {
        func_02011298(*(void **)(p + 4));
        if (*(u16 *)(p + 0x16) & 1) {
            func_02011290(*(void **)(p + 4));
            func_02011264(*(void **)(p + 4));
            if (*(u16 *)(p + 0x16) & 8) func_020307B0(*(void **)(p + 0xc));
            return 1;
        }
    }
    (*(int *)(p + 0x10))++;
    return 0;
}
