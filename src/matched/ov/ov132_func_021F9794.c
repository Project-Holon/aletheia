/*
 * function: func_021F9794
 * address: 0x021F9794
 * packet: pkt_ov132_021F9794
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * lever: slots[count] = i; count++; keeps the byte store before the increment; if/else field stores preserve the shared flag-store block.
 * symbols:
 *   func_021F9A48 0x021F9A48 thumb ov132
 *   func_021FD8C4 0x021FD8C4 thumb ov132
 *   func_021F79A8 0x021F79A8 thumb ov112
 *   func_021F9AD8 0x021F9AD8 thumb ov132
 *   func_02005728 0x02005728 thumb
 *   func_021FD9FC 0x021FD9FC thumb ov132
 *   func_021FD9A0 0x021FD9A0 thumb ov132
 *   func_021FDA18 0x021FDA18 thumb ov132
 *   func_021FD9D0 0x021FD9D0 thumb ov132
 *   func_021F99F4 0x021F99F4 thumb ov132
 *   func_020061E4 0x020061E4 thumb
 *   func_0203D378 0x0203D378 arm
 *   func_021FDA24 0x021FDA24 thumb ov132
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void func_021F9A48(char *);
extern int func_021FD8C4(void *, int);
extern void func_021F79A8(char *, char *, int);
extern void func_021F9AD8(char *, int, unsigned);
extern u32 func_02005728(u32);
extern int func_021FD9FC(void *);
extern int func_021FD9A0(void *, unsigned);
extern void func_021FDA18(void *);
extern void func_021FD9D0(void *, unsigned);
extern int func_021F99F4(char *, unsigned, unsigned);
extern void func_020061E4(int);
extern int func_0203D378(void *);
extern void func_021FDA24(void *, u32, u32, u32);
void func_021F9794(char *p)
{
    u8 count = 0;
    u8 slots[4];
    u8 i;
    int action;
    int index;
    int result;
    func_021F9A48(p);
    if (**(void ***)(p + 0x30) && *(int *)(p + 0x15C) == 1) {
        if (func_021FD8C4(**(void ***)(p + 0x30), (u8)*(int *)(p + 0x160)) == 1)
            *(int *)(p + 0x15C) = 0;
    }
    if (!**(void ***)(p + 0x30)) {
        for (i = 0; i < 4; i++) {
            if (*(int *)(p + i * 4 + 0xFC) == 1) {
                func_021F79A8(*(char **)(p + 0x40), *(char **)(p + i * 4 + 0x44), *(int *)(p + i * 4 + 0x10C));
                slots[count] = i;
                count++;
                *(int *)(p + i * 4 + 0xFC) = 0;
                if (*(int *)(p + i * 4 + 0x10C) == 7) *(int *)(p + i * 8 + 0x13C) = 1;
                else if (*(int *)(p + i * 4 + 0x10C) == 8) *(int *)(p + i * 8 + 0x140) = 1;
                func_021F9AD8(p, 2, i);
            }
        }
        if (count != 0) {
            if (*(u8 *)(p + 0x11C) == 4) *(int *)(p + 0x120) = 1;
            else *(int *)(p + 0x120) = 0;
            *(u16 *)(p + 0x11E) = 180;
            *(u8 *)(p + 0x11C) = slots[func_02005728(count)];
            *(u8 *)(p + 0x11D) = *(int *)(p + *(u8 *)(p + 0x11C) * 4 + 0x10C);
            *(int *)(p + 0xEC) = 1;
        }
    } else {
        index = func_021FD9FC(**(void ***)(p + 0x30));
        if ((unsigned)index < 4) {
            if (*(u8 *)(p + 0x11C) == 4) *(int *)(p + 0x120) = 1;
            else *(int *)(p + 0x120) = 0;
            *(u16 *)(p + 0x11E) = 180;
            *(u8 *)(p + 0x11C) = index;
            *(u8 *)(p + 0x11D) = func_021FD9A0(**(void ***)(p + 0x30), index);
            *(int *)(p + 0xEC) = 1;
            func_021FDA18(**(void ***)(p + 0x30));
        }
        for (i = 0; i < 4; i++) {
            action = func_021FD9A0(**(void ***)(p + 0x30), i);
            if (action != 10) {
                func_021F79A8(*(char **)(p + 0x40), *(char **)(p + i * 4 + 0x44), action);
                func_021FD9D0(**(void ***)(p + 0x30), i);
                if (action == 7) *(int *)(p + i * 8 + 0x13C) = 1;
                else if (action == 8) *(int *)(p + i * 8 + 0x140) = 1;
                func_021F9AD8(p, 2, i);
            }
        }
    }
    if (*(u16 *)(p + 0x11E) != 0) {
        if (*(u16 *)(p + 0x11E) > *(u32 *)(p + 0x1E8)) {
            *(u16 *)(p + 0x11E) -= (u16)*(u32 *)(p + 0x1E8);
            return;
        }
        *(u16 *)(p + 0x11E) = 0;
        if (*(int *)(p + 0x120) == 1) {
            if (!**(void ***)(p + 0x30)) {
                result = func_021F99F4(p, *(u8 *)(p + 0x11C), *(u8 *)(p + 0x11D));
                *(int *)(*(char **)(*(char **)(p + 0x30) + *(u8 *)(p + 0x11C) * 4 + 4) + *(u8 *)(p + 0x11D) * 4 + 0x54) = 1;
                func_020061E4(result);
            } else if (func_0203D378(**(void ***)(p + 0x30)) == 1) {
                result = func_021F99F4(p, *(u8 *)(p + 0x11C), *(u8 *)(p + 0x11D));
                if (result == 1580) func_021FDA24(**(void ***)(p + 0x30), *(u8 *)(p + 0x11C), *(u8 *)(p + 0x11D), 1);
                else func_021FDA24(**(void ***)(p + 0x30), *(u8 *)(p + 0x11C), *(u8 *)(p + 0x11D), 2);
            }
        }
        *(u8 *)(p + 0x11C) = 4;
        *(int *)(p + 0xEC) = 1;
    }
}
