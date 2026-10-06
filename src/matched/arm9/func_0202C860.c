/*
 * function: func_0202C860
 * address:  0x0202C860
 * packet:   pkt_0202C860
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     2026-09-23 (wave 15): EXACT with no C change; the ov010 call
 *           at +0x34 now resolves sole-ref/code.  The MATCH text below is history.
 *
 * Blocked at MATCH on the `label`/`matched` classes: all 82 concrete bytes
 * are correct (88-byte extent, the last 6 bytes being the pool word 0xffff),
 * but the PC-relative call at +0x0034 to func_0215E6F8 in ov010 has no
 * witness: 0x0215E6F8 has exactly one branch reference image-wide and it is
 * that call, so no cut frees it, and the address is inside BOTH ov009's and
 * ov010's windows, so the `label` class refuses it even with the ov010 hint
 * on the symbols: line.  The unblock is a `matched` entry at 0x0215E6F8
 * (or any additional caller of it anywhere in the image).
 *
 * The range check must wrap in 32 bits: `(u32)(r - 6) > 1`, `(r - 6) > 1u`
 * and `(unsigned)(r - 6) > 1` all give the original's bare
 * `subs r0, r1, #6; cmp r0, #1; bhi`.  The u16-cast spelling
 * `(u16)(r - 6) > 1` is wrong by two instructions: it re-truncates the
 * difference with `lsls r0, r0, #0x10; lsrs r0, r0, #0x10` first.
 *
 * The first call takes the actor pointer as well as the truncated id,
 * `func_0215E6A8(a0, (u16)a1)`: r0 is still r0 at the call and the id is
 * built in r1.  Declaring it as a one-argument call puts the id in r0 and
 * shifts the whole prologue.
 *
 * symbols:
 *   func_0215E6A8  0x0215E6A8  thumb ov010
 *   func_0215E6F8  0x0215E6F8  thumb ov010
 *   func_02012994  0x02012994  thumb
 *   func_020129A0  0x020129A0  thumb
 *   func_02013C10  0x02013C10  thumb
 */


typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int func_0215E6A8(void *a, int x);
extern u32 func_0215E6F8(u8 *a0);
struct BigObj;
extern u8 func_02012994(const struct BigObj *p);
struct BigObj;
extern void func_020129A0(struct BigObj *p, u8 v);
extern u32 func_02013C10(u32 id);

void func_0202C860(u8 *a0, int a1)
{
    u32 v;
    u16 r;

    v = func_0215E6A8(a0, (u16)a1);
    r = (u16)(u32)func_02012994((const struct BigObj *)a0);
    if (v != 0xffff) {
        func_020129A0((struct BigObj *)a0, (u8)v);
        return;
    }
    if ((u32)(r - 6) > 1) {
        return;
    }
    if (func_0215E6F8(a0) != 1) {
        return;
    }
    func_020129A0((struct BigObj *)a0, (u8)func_02013C10((u16)a1));
}
