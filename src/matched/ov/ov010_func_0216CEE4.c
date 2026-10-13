/*
 * function: FLDMMDL_AddMmdlHeaderById
 * address:  0x0216CEE4
 * packet:   pkt_ov010_0216CEE4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * The result local is never initialised on the not-found path (the
 * original returns whatever stack slot it had).
 *
 * symbols:
 *   FLDMMDL_HeaderIsEventIdNone  0x0216E418  thumb  ov010
 *   FLDMMDL_CheckEventFlagBit  0x0216E42C  thumb  ov010
 *   FLDMMDL_AddMmdlCore  0x0216CDC4  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u16 id;
    u16 pad0[3];
    u16 key;
    u16 pad1[13];
} Ent;

extern int FLDMMDL_HeaderIsEventIdNone(void *a);
extern unsigned int FLDMMDL_CheckEventFlagBit(void *bitmap, int id);
extern int FLDMMDL_AddMmdlCore(u32 a, Ent *e, u32 b, u32 c);

int FLDMMDL_AddMmdlHeaderById(u32 a, Ent *e, u32 b, int n, u32 c, u32 id)
{
    int r;

    do {
        if (FLDMMDL_HeaderIsEventIdNone(e) == 0 && e->id == id && FLDMMDL_CheckEventFlagBit((void *)c, e->key) == 0) {
            r = FLDMMDL_AddMmdlCore(a, e, b, c);
            break;
        }
        e++;
    } while (--n);
    return r;
}
