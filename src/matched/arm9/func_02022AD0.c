/*
 * unit:     no
 * function: func_02022AD0
 * address:  0x02022AD0
 * packet:   pkt_02022AD0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02022D88  0x02022D88  thumb
 *
 * The four pool words at 0x02022CDC are 0x04000006, 0x04000004,
 * 0x04001040 and 0x04001042: I/O register addresses, written as cast
 * constants, not relocations.
 *
 * The 8-byte residue docs/notes/func_02022AD0.c.txt records at +0x00CC
 * is closed by ONE statement order: block two must read ctl->sel BEFORE
 * its three array reads, exactly as blocks one and three do.  With
 * sel read last (the note's C) the 0x180 constant is hoisted one slot
 * early and the y[] address lands in r0 instead of r1; with sel first
 * the block is byte-identical to its two neighbours.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed int     s32;

struct ctl {
    u32 pad0;
    u32 mode;
    u32 sel;
};

struct sched {
    s16 x[0xc0];
    s16 y[0xc0];
    u8  pad[0x300];
    u32 flag;
};

struct Obj;
extern void *func_02022D88(struct Obj *obj, u32 idx);

#define REG_VCOUNT  (*(volatile u16 *)0x04000006)
#define REG_A       ((volatile u16 *)0x04000004)
#define REG_B       ((volatile u16 *)0x04001040)
#define REG_C       ((volatile u16 *)0x04001042)

void func_02022AD0(struct ctl *ctl)
{
    struct sched *p;
    s32 line;
    s32 next;
    s32 x;
    s32 y;
    u32 flag;
    u32 sel;

    line = REG_VCOUNT;
    if (line >= 0xc0) {
        return;
    }
    next = line + 1;
    if (next > 0xbf) {
        next -= 0xc0;
    }

    if (ctl->mode == 1) {
        p = func_02022D88((struct Obj *)ctl, 0);
        sel = ctl->sel;
        y = p->y[next];
        x = p->x[next];
        flag = p->flag;
        if (flag == 0) {
            if (sel == 0) {
                if ((REG_A[0] & 2) != 0) {
                    REG_A[0x1e] = ((x << 8) & 0xff00) | (u32)(u8)y;
                    REG_A[0x20] = 0xc0;
                }
            } else {
                if ((REG_A[0] & 2) != 0) {
                    REG_B[0] = ((x << 8) & 0xff00) | (u32)(u8)y;
                    REG_B[2] = 0xc0;
                }
            }
        } else {
            if (sel == 0) {
                if ((REG_A[0] & 2) != 0) {
                    REG_A[0x1f] = ((x << 8) & 0xff00) | (u32)(u8)y;
                    REG_A[0x21] = 0xc0;
                }
            } else {
                if ((REG_A[0] & 2) != 0) {
                    REG_C[0] = ((x << 8) & 0xff00) | (u32)(u8)y;
                    REG_C[2] = 0xc0;
                }
            }
        }
        return;
    }

    p = func_02022D88((struct Obj *)ctl, 0);
    sel = ctl->sel;
    y = p->y[next];
    x = p->x[next];
    flag = p->flag;
    if (flag == 0) {
        if (sel == 0) {
            if ((REG_A[0] & 2) != 0) {
                REG_A[0x1e] = ((x << 8) & 0xff00) | (u32)(u8)y;
                REG_A[0x20] = 0xc0;
            }
        } else {
            if ((REG_A[0] & 2) != 0) {
                REG_B[0] = ((x << 8) & 0xff00) | (u32)(u8)y;
                REG_B[2] = 0xc0;
            }
        }
    } else {
        if (sel == 0) {
            if ((REG_A[0] & 2) != 0) {
                REG_A[0x1f] = ((x << 8) & 0xff00) | (u32)(u8)y;
                REG_A[0x21] = 0xc0;
            }
        } else {
            if ((REG_A[0] & 2) != 0) {
                REG_C[0] = ((x << 8) & 0xff00) | (u32)(u8)y;
                REG_C[2] = 0xc0;
            }
        }
    }

    p = func_02022D88((struct Obj *)ctl, 1);
    sel = ctl->sel;
    y = p->y[next];
    x = p->x[next];
    flag = p->flag;
    if (flag == 0) {
        if (sel == 0) {
            if ((REG_A[0] & 2) != 0) {
                REG_A[0x1e] = ((x << 8) & 0xff00) | (u32)(u8)y;
                REG_A[0x20] = 0xc0;
            }
        } else {
            if ((REG_A[0] & 2) != 0) {
                REG_B[0] = ((x << 8) & 0xff00) | (u32)(u8)y;
                REG_B[2] = 0xc0;
            }
        }
    } else {
        if (sel == 0) {
            if ((REG_A[0] & 2) != 0) {
                REG_A[0x1f] = ((x << 8) & 0xff00) | (u32)(u8)y;
                REG_A[0x21] = 0xc0;
            }
        } else {
            if ((REG_A[0] & 2) != 0) {
                REG_C[0] = ((x << 8) & 0xff00) | (u32)(u8)y;
                REG_C[2] = 0xc0;
            }
        }
    }
}
