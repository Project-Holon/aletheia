/*
 * function: func_021B96BC
 * address: 0x021B96BC
 * packet: pkt_ov182_021B96BC
 * region: ov182
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: follower 021B9784 already matched separately.
 * symbols:
 *   func_0204E804 0x0204E804 arm
 *   func_020362DC 0x020362DC arm
 *   func_0201C4E4 0x0201C4E4 thumb
 *   func_021B9788 0x021B9788 thumb ov182
 *   func_021B9814 0x021B9814 thumb ov182
 *   func_021B99E8 0x021B99E8 thumb ov182
 */
typedef unsigned short u16;
extern int func_0204E804(void);
extern unsigned func_020362DC(void);
extern int func_0201C4E4(void *);
extern void func_021B9788(u16 *);
extern void func_021B9814(void *, void *, void *);
extern void func_021B99E8(char *);
int func_021B96BC(void *a, unsigned *state, void *c, char *p)
{
    int ready;
    switch (*state) {
    case 0: *state = 4; break;
    case 1:
        if (!func_0204E804()) *state = 2;
        break;
    case 2:
        ready = 0;
        if (++*(int *)(p + 0x18) > 0x384) ready = 1;
        if (ready) {
            *state = 3;
            func_021B9814(0, (void *)0x10, 0);
        }
        break;
    case 3:
        if (!func_0204E804()) {
            func_021B9788((u16 *)p);
            func_021B9814((void *)0x10, 0, 0);
            *state = 4;
        }
        break;
    case 4:
        if (!func_0204E804()) {
            *(int *)(p + 0x18) = 0;
            *state = 5;
        }
        break;
    case 5:
        if ((func_020362DC() & 0xb) || ++*(int *)(p + 0x18) > 0x384) {
            *state = 6;
            func_021B9814(0, (void *)0x10, 0);
        }
        break;
    case 6:
        if (!func_0204E804()) *state = 7;
        break;
    case 7: return 1;
    }
    func_0201C4E4(*(void **)(p + 0xc));
    func_021B99E8(*(char **)(p + 4));
    return 0;
}
