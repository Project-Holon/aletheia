/*
 * function: func_022033CC
 * address:  0x022033CC
 * packet:   pkt_ov094_022033CC
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * isa:      thumb
 * status:   EXACT*
 * trailing: 022033F0..022033F4 is an unlabelled 4-byte getter (ldr r0, [r0, #0x58]; bx lr).
 *
 * symbols:
 *   func_02021ED8  0x02021ED8  thumb
 */
typedef struct Bits { unsigned b0:1; unsigned mid:30; unsigned b31:1; } Bits;
typedef struct Obj { char pad[0x64]; void *h64; Bits f68; } Obj;
extern int func_02021ED8(void *);

int func_022033CC(Obj *p)
{
    if (p->f68.b0 || func_02021ED8(p->h64) != 0 || p->f68.b31)
        return 1;
    return 0;
}
