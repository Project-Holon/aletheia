/*
 * function: func_02049C28
 * address:  0x02049C28
 * packet:   pkt_02049C28
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_020A1364     0x020A1364  data
 *   func_02062AD4  0x02062AD4  arm
 *   func_02062A98  0x02062A98  arm
 *   func_020862F0  0x020862F0  arm
 *   func_0207F308  0x0207F308  arm
 *   func_0207F428  0x0207F428  arm
 *   func_0207F5B0  0x0207F5B0  arm
 *   func_0207F65C  0x0207F65C  arm
 *   func_0207F47C  0x0207F47C  arm
 *   func_0207F560  0x0207F560  arm
 *   func_0207F6A8  0x0207F6A8  arm
 *   func_0207F754  0x0207F754  arm
 *   func_020307B0  0x020307B0  arm
 *
 * arc_tool.c (wave 13): load a palette resource into VRAM.  With a loaded
 * resource file: look up its PMCP block (optional) and its PLTT block; when
 * the PLTT block is there, advance its data pointer by `offset`, and when the
 * caller passed size 0 take the block's own size (no PMCP) or the PMCP count
 * times 0x20 (format 3) / 0x200 (anything else), less `offset`; flush the
 * range and dispatch through the eight-entry loader table 0x020A1364 by
 * `kind`, wrapping kinds 2/6/3/7 (source order, which is what the emitted
 * bodies say) in the matching Begin/End extended-palette calls.  The file is
 * released either way.
 *
 * WHAT CLOSED IT (docs/notes/pkt_02049C28.c.txt: 20 bytes out, "a4 in r5 at
 * entry, v separately"):
 *   - there is no separate `v`: the size PARAMETER is the value that is
 *     defaulted, reduced by offset and passed on (`size = ...; size -=
 *     offset;`), which is why the image loads it into r5 at entry and keeps
 *     it there;
 *   - the early `if (file == 0) return;` the note's shape omitted (the
 *     image's `movs sb, r0` / `addeq` / `popeq`);
 *   - the two out-pointer locals declared PLTT first, PMCP second, so PMCP
 *     lands at sp+0 and PLTT at sp+4.
 * The table's const qualifier does not change the bytes.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Pltt {
    u32 fmt;
    u8  pad04[4];
    u32 size;
    u32 data;
};

typedef void (*LoadFn)(u32 data, u32 dest, u32 size);
extern const LoadFn g_020A1364[];

extern int  func_02062AD4(void *file, u16 **pmcp);
extern int  func_02062A98(void *file, struct Pltt **pltt);
extern void func_020862F0(u32 addr, u32 size);
extern void func_0207F308(void);
extern void func_0207F428(void);
extern void func_0207F5B0(void);
extern void func_0207F65C(void);
extern void func_0207F47C(void);
extern void func_0207F560(void);
extern void func_0207F6A8(void);
extern void func_0207F754(void);
extern void func_020307B0(void *file);

void func_02049C28(void *file, u32 kind, u32 offset, u32 dest, u32 size)
{
    struct Pltt *pltt;
    u16 *pmcp;
    int cmp;

    if (file == 0)
        return;
    cmp = func_02062AD4(file, &pmcp);
    if (func_02062A98(file, &pltt) != 0) {
        pltt->data += offset;
        if (size == 0) {
            if (cmp == 0)
                size = pltt->size;
            else
                size = *pmcp * (pltt->fmt == 3 ? 0x20 : 0x200);
            size -= offset;
        }
        func_020862F0(pltt->data, size);
        switch (kind) {
        case 2:
            func_0207F308();
            g_020A1364[kind](pltt->data, dest, size);
            func_0207F428();
            break;
        case 6:
            func_0207F5B0();
            g_020A1364[kind](pltt->data, dest, size);
            func_0207F65C();
            break;
        case 3:
            func_0207F47C();
            g_020A1364[kind](pltt->data, dest, size);
            func_0207F560();
            break;
        case 7:
            func_0207F6A8();
            g_020A1364[kind](pltt->data, dest, size);
            func_0207F754();
            break;
        case 0:
        case 1:
        case 4:
        case 5:
        default:
            g_020A1364[kind](pltt->data, dest, size);
            break;
        }
    }
    func_020307B0(file);
}
