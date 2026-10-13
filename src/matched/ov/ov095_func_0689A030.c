/*
 * function: BTLV_SCD_OpenActionMenuStep
 * address: 0x0689A030
 * packet: pkt_ov095_0689A030
 * region: ov095
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * blocker: 28 unresolved Thumb-to-Thumb linker veneers at 0689A4CC..0689A67C.
 *   Each is bx pc; mov r8,r8; ARM ldr ip,[pc]; bx ip; target+1.
 *   Four repeated groups call 021B8ED8,021B98AC,021D5B68,021D5444,
 *   021D5864,02017E1C,021D59B4. They have no label/seed evidence.
 * prototype: full r1 arguments at A4DC/A54C/A5BC/A62C avoid unwitnessed
 *   byte truncation; A70C retains the observed narrow argument.
 * shape: the 200-byte cleared payload fixes the record and trailer layout.
 * symbols:
 *   func_0689A3E4 0x0689A3E4 arm ov095
 *   func_0689A3EC 0x0689A3EC thumb ov095
 *   func_0689A3FC 0x0689A3FC thumb ov095
 *   func_0689A40C 0x0689A40C thumb ov095
 *   func_0689A41C 0x0689A41C thumb ov095
 *   func_0689A42C 0x0689A42C thumb ov095
 *   func_0689A43C 0x0689A43C thumb ov095
 *   func_0689A44C 0x0689A44C thumb ov095
 *   func_0689A45C 0x0689A45C thumb ov095
 *   func_0689A46C 0x0689A46C thumb ov095
 *   func_0689A47C 0x0689A47C thumb ov095
 *   func_0689A48C 0x0689A48C thumb ov095
 *   func_0689A49C 0x0689A49C thumb ov095
 *   func_0689A4AC 0x0689A4AC thumb ov095
 *   func_0689A4BC 0x0689A4BC thumb ov095
 *   func_0689A4CC 0x0689A4CC thumb ov095
 *   func_0689A4DC 0x0689A4DC thumb ov095
 *   func_0689A4EC 0x0689A4EC thumb ov095
 *   func_0689A4FC 0x0689A4FC thumb ov095
 *   func_0689A50C 0x0689A50C thumb ov095
 *   func_0689A51C 0x0689A51C thumb ov095
 *   func_0689A52C 0x0689A52C thumb ov095
 *   func_0689A53C 0x0689A53C thumb ov095
 *   func_0689A54C 0x0689A54C thumb ov095
 *   func_0689A55C 0x0689A55C thumb ov095
 *   func_0689A56C 0x0689A56C thumb ov095
 *   func_0689A57C 0x0689A57C thumb ov095
 *   func_0689A58C 0x0689A58C thumb ov095
 *   func_0689A59C 0x0689A59C thumb ov095
 *   func_0689A5AC 0x0689A5AC thumb ov095
 *   func_0689A5BC 0x0689A5BC thumb ov095
 *   func_0689A5CC 0x0689A5CC thumb ov095
 *   func_0689A5DC 0x0689A5DC thumb ov095
 *   func_0689A5EC 0x0689A5EC thumb ov095
 *   func_0689A5FC 0x0689A5FC thumb ov095
 *   func_0689A60C 0x0689A60C thumb ov095
 *   func_0689A61C 0x0689A61C thumb ov095
 *   func_0689A62C 0x0689A62C thumb ov095
 *   func_0689A63C 0x0689A63C thumb ov095
 *   func_0689A64C 0x0689A64C thumb ov095
 *   func_0689A65C 0x0689A65C thumb ov095
 *   func_0689A66C 0x0689A66C thumb ov095
 *   func_0689A67C 0x0689A67C thumb ov095
 *   func_0689A68C 0x0689A68C thumb ov095
 *   func_0689A69C 0x0689A69C thumb ov095
 *   func_0689A6AC 0x0689A6AC thumb ov095
 *   func_0689A6BC 0x0689A6BC thumb ov095
 *   func_0689A6CC 0x0689A6CC thumb ov095
 *   func_0689A6DC 0x0689A6DC thumb ov095
 *   func_0689A6EC 0x0689A6EC thumb ov095
 *   func_0689A6FC 0x0689A6FC thumb ov095
 *   func_0689A70C 0x0689A70C thumb ov095
 *   func_0689A71C 0x0689A71C thumb ov095
 *   func_0689A72C 0x0689A72C thumb ov095
 *   func_0689A73C 0x0689A73C thumb ov095
 *   func_0689A74C 0x0689A74C thumb ov095
 *   func_0689A75C 0x0689A75C thumb ov095
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u8 bytes[12]; } Rec;
typedef struct { Rec rows[2][6]; u32 f90, f94; u32 ids[3], names[3], values[3]; u32 fbc, fc0; u8 fc4, fc5, pad[2]; } Payload;
extern void func_0689A3E4(u32, void *, u32);
extern u8 func_0689A3EC(void *);
extern u32 func_0689A3FC(void *, void *, u32);
extern u8 func_0689A40C(void *, u32);
extern void func_0689A41C(u32);
extern u32 func_0689A42C(void *);
extern u32 func_0689A43C(void *);
extern u32 func_0689A44C(void *);
extern void *func_0689A45C(void *, int);
extern u32 func_0689A46C(void *);
extern void *func_0689A47C(void *, int);
extern u32 func_0689A48C(void *);
extern void *func_0689A49C(void *, int);
extern u32 func_0689A4AC(void *);
extern u32 func_0689A4BC(void *);
extern u8 func_0689A4CC(void *, u32);
extern void *func_0689A4DC(void *, u32);
extern int func_0689A4EC(void *);
extern u32 func_0689A4FC(void *);
extern void *func_0689A50C(void *);
extern u32 func_0689A51C(void *, int, int);
extern u32 func_0689A52C(void *, int);
extern u8 func_0689A53C(void *, u32);
extern void *func_0689A54C(void *, u32);
extern int func_0689A55C(void *);
extern u32 func_0689A56C(void *);
extern void *func_0689A57C(void *);
extern u32 func_0689A58C(void *, int, int);
extern u32 func_0689A59C(void *, int);
extern u8 func_0689A5AC(void *, u32);
extern void *func_0689A5BC(void *, u32);
extern int func_0689A5CC(void *);
extern u32 func_0689A5DC(void *);
extern void *func_0689A5EC(void *);
extern u32 func_0689A5FC(void *, int, int);
extern u32 func_0689A60C(void *, int);
extern u8 func_0689A61C(void *, u32);
extern void *func_0689A62C(void *, u32);
extern int func_0689A63C(void *);
extern u32 func_0689A64C(void *);
extern void *func_0689A65C(void *);
extern u32 func_0689A66C(void *, int, int);
extern u32 func_0689A67C(void *, int);
extern void *func_0689A68C(void *);
extern u32 func_0689A69C(void *);
extern u8 func_0689A6AC(void *, int);
extern u8 func_0689A6BC(void *, int);
extern void *func_0689A6CC(void *, int);
extern u32 func_0689A6DC(void *);
extern void *func_0689A6EC(void *, int);
extern u32 func_0689A6FC(void *);
extern void *func_0689A70C(void *, u8);
extern int func_0689A71C(void *);
extern int func_0689A72C(void *);
extern int func_0689A73C(void *);
extern u8 func_0689A74C(void *);
extern void func_0689A75C(void *, int, void *);
int BTLV_SCD_OpenActionMenuStep(int unused, u8 *p)
{
    u16 n, pass, index;
    void *groups[2] = {0, 0};
    u16 counts[2] = {0, 0};
    u32 mode, first, second, side, slot;
    void *mon;
    Payload out;
    pass = 0;
    func_0689A3E4(0, &out, 200);
    out.fc0 = p[0x90];
    out.fc4 = p[0x91];
    first = func_0689A3EC(*(void **)(p + 0x6c));
    first = func_0689A3FC(*(void **)(p + 0xa0), *(void **)(p + 0xa4), first);
    out.fbc = func_0689A40C(*(void **)(p + 0xa0), first);
    func_0689A41C(out.fbc);
    mode = func_0689A42C(*(void **)(p + 0xa0));
    for (; pass < 2; pass++) {
        groups[0] = 0;
        groups[1] = 0;
        if (pass == 0) {
            first = func_0689A43C(*(void **)(p + 0xa0));
            second = func_0689A44C(*(void **)(p + 0xa0));
            if (mode == 1 && second != 4) {
                if (first < second) {
                    groups[0] = func_0689A45C(*(void **)(p + 0xa4), first);
                    counts[0] = func_0689A46C(groups[0]);
                    groups[1] = func_0689A47C(*(void **)(p + 0xa4), second);
                    counts[1] = func_0689A48C(groups[1]);
                } else {
                    groups[0] = func_0689A49C(*(void **)(p + 0xa4), second);
                    counts[0] = func_0689A4AC(groups[0]);
                    groups[1] = func_0689A47C(*(void **)(p + 0xa4), first);
                    counts[1] = func_0689A48C(groups[1]);
                }
            } else {
                groups[0] = *(void **)(p + 0xa8);
                counts[0] = func_0689A4BC(groups[0]);
            }
            switch (mode) {
            case 0:
                slot = func_0689A4CC(*(void **)(p + 0xa0), 0);
                mon = func_0689A4DC(*(void **)(p + 0xa4), slot);
                if (func_0689A4EC(mon) == 0) {
                    out.ids[0] = func_0689A4FC(mon);
                    out.names[0] = func_0689A51C(func_0689A50C(mon), 111, 0);
                    out.values[0] = func_0689A52C(mon, 18);
                }
                break;
            case 2:
                slot = func_0689A53C(*(void **)(p + 0xa0), 6);
                mon = func_0689A54C(*(void **)(p + 0xa4), slot);
                if (func_0689A55C(mon) == 0) {
                    out.ids[2] = func_0689A56C(mon);
                    out.names[2] = func_0689A58C(func_0689A57C(mon), 111, 0);
                    out.values[2] = func_0689A59C(mon, 18);
                }
            case 1: case 3:
                slot = func_0689A5AC(*(void **)(p + 0xa0), 2);
                mon = func_0689A5BC(*(void **)(p + 0xa4), slot);
                if (func_0689A5CC(mon) == 0) {
                    out.ids[0] = func_0689A5DC(mon);
                    out.names[0] = func_0689A5FC(func_0689A5EC(mon), 111, 0);
                    out.values[0] = func_0689A60C(mon, 18);
                }
                slot = func_0689A61C(*(void **)(p + 0xa0), 4);
                mon = func_0689A62C(*(void **)(p + 0xa4), slot);
                if (func_0689A63C(mon) == 0) {
                    out.ids[1] = func_0689A64C(mon);
                    out.names[1] = func_0689A66C(func_0689A65C(mon), 111, 0);
                    out.values[1] = func_0689A67C(mon, 18);
                }
                break;
            default: break;
            }
        } else {
            if (func_0689A68C(*(void **)(p + 0xa0)) == 0 || func_0689A69C(*(void **)(p + 0xa0)) == 4) break;
            first = func_0689A6AC(*(void **)(p + 0xa0), 0);
            second = func_0689A6BC(*(void **)(p + 0xa0), 1);
            out.f94 = 1;
            groups[0] = func_0689A6CC(*(void **)(p + 0xa4), first);
            counts[0] = func_0689A6DC(groups[0]);
            if (mode == 1 && first != second) {
                groups[1] = func_0689A6EC(*(void **)(p + 0xa4), second);
                counts[1] = func_0689A6FC(groups[1]);
            }
        }
        if (groups[1] == 0) n = counts[0];
        else {
            if (counts[0] > 3) counts[0] = 3;
            if (counts[1] > 3) counts[1] = 3;
            n = counts[0] + counts[1];
        }
        for (index = 0; index < n; index++) {
            if (index < counts[0]) { side = 0; slot = index; }
            else { side = 1; slot = index - counts[0]; }
            mon = func_0689A70C(groups[side], slot);
            if (func_0689A71C(mon) == 0) {
                if (func_0689A72C(mon) != 0) out.rows[pass][side * 3 + slot].bytes[1] = 3;
                else if (func_0689A73C(mon) == 0) out.rows[pass][side * 3 + slot].bytes[1] = 0;
                else out.rows[pass][side * 3 + slot].bytes[1] = 1;
            } else out.rows[pass][side * 3 + slot].bytes[1] = 2;
        }
    }
    out.f90 = p[0x8b];
    out.fc5 = func_0689A74C(*(void **)(p + 0x10));
    p += 0xb0;
    func_0689A75C(*(void **)p, 1, &out);
    return 1;
}
