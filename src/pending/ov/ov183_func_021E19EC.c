/*
 * function: func_021E19EC
 * address: 0x021E19EC
 * packet: pkt_ov183_021E19EC
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: DIFF
 * note: 2026-10-05 wave P5 lane T5 (pengy share). Body matches except two items.
 *   (1) The original has two separate far-branch stubs at the top (beq next; b end, twice);
 *   the compiler threads the first bne onto the second stub (2 bytes less). Tried: nested ifs,
 *   && form, early returns, goto.
 *   (2) The two divisions (idx-12)%5 and (idx-12)/5: the original recomputes idx-12 for each
 *   call; the draft keeps it in r7 (CSE). With u32 idx there is no CSE but the idx>=12&&idx<=21
 *   test folds to subs/cmp #9; with u8 idx (no fold, as in the original) the CSE appears.
 *   opt_common_subs off recolours the whole function (worse). The store as an argument
 *   func_021E0E40(rec[i].tag = v, ...) and old = rec[i].value after the call follow the matched
 *   sibling func_021E1850 and close the tail.
 *   Callbacks: func_021E1910 passes this as func_02051B84's callback (idx, arg, obj).
 * symbols:
 *   func_021E0E40 0x021E0E40 thumb ov183
 *   func_021E1708 0x021E1708 thumb ov183
 *   func_021E1850 0x021E1850 thumb ov183
 *   func_0204B878 0x0204B878 arm
 *   func_02035D20 0x02035D20 arm
 *   func_020061E4 0x020061E4 thumb
 *   func_021FD860 0x021FD860 thumb ov186
 *   _u32_div_f 0x0209C2B0 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {int tag,value,mode,handle; char rest[12];} Record;
struct Obj;
extern int func_021E0E40(int,int);
extern void func_021E1708(char *);
extern void func_021E1850(char *);
extern void func_0204B878(struct Obj *, u16);
extern int func_02035D20(u32 *,u32 *);
extern void func_020061E4(u32);
extern void func_021FD860(int,int,int *);
void func_021E19EC(u8 idx, int arg, char *p)
{
    Record *rec = (Record *)p;
    u32 i, j, v;
    int old, val;
    if (*(int *)(p + 0x22C) == 1 && arg == 0) {
    if (idx <= 11) {
        if (rec[idx].mode == 1) {
            *(int *)(p + 0x318) = 2;
            *(int *)(p + 0x31C) = idx;
        } else {
            *(int *)(p + 0x318) = 1;
            *(int *)(p + 0x31C) = rec[idx].value;
        }
        func_020061E4(0x703);
        return;
    }
    if (idx == 0x16) {
        u32 x, y;
        int args[2];
        *(u16 *)(p + 0x1B8) = 0;
        *(u16 *)(p + 0x1BA) = 2;
        func_020061E4(0x703);
        func_02035D20(&x, &y);
        args[0] = x;
        args[1] = y;
        func_021FD860(*(int *)(p + 0x348), 1, args);
    } else if (idx == 0x17) {
        u32 x, y;
        int args[2];
        *(u16 *)(p + 0x1B8) = 3;
        *(u16 *)(p + 0x1BA) = 2;
        func_020061E4(0x703);
        func_02035D20(&x, &y);
        args[0] = x;
        args[1] = y;
        func_021FD860(*(int *)(p + 0x348), 1, args);
    } else {
        *(u16 *)(p + 0x1B8) = (idx - 12) % 5U;
        *(u16 *)(p + 0x1BA) = (idx - 12) / 5U;
        func_020061E4(0x703);
    }
    if (idx >= 12 && idx <= 21) {
        u32 x, y;
        int args[2];
        if (*(int *)(p + 0x240) != 0) {
        func_02035D20(&x, &y);
        args[0] = x;
        args[1] = y;
        func_021FD860(*(int *)(p + 0x348), 1, args);
        i = *(int *)(p + 0x188);
        v = idx - 11;
        func_0204B878((struct Obj *)rec[i].handle, (u16)func_021E0E40(rec[i].tag = v, rec[i].mode));
        old = rec[i].value;
        j = i + 1;
        if (j == *(u32 *)(p + 0x23C)) {
            *(int *)(p + 0x318) = 1;
            *(int *)(p + 0x31C) = 0;
            *(int *)(p + 0x320) = 0;
        } else {
            val = rec[j].value;
            if (old != val) {
                *(int *)(p + 0x318) = 1;
                *(int *)(p + 0x31C) = val;
                *(int *)(p + 0x320) = 0;
            } else {
                *(int *)(p + 0x318) = 2;
                *(int *)(p + 0x31C) = j;
            }
        }
        }
    } else if (idx == 0x16) {
        func_021E1850(p);
    } else {
        func_021E1708(p);
    }
    }
}
