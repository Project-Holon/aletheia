/*
 * function: ISS_SYS_SwitchMode
 * address:  0x0202B84C
 * packet:   pkt_0202B84C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * note:     wave 16: promoted.  0x0209FF8C was never a second table: it is
 *           ISS_SYS_ModeTable + 4, the `enter` field of entry v, which the
 *           compiler reaches through its own pool word because a register
 *           offset load has no immediate (docs/idioms/
 *           pool-base-for-a-far-field-is-the-symbol-offset-masked-by-the-load-reach.md).
 *           One symbol, one struct with both callbacks; the +4 site then
 *           resolves against the attested 0x0209FF88.
 * symbols:
 *   ISS_SYS_ModeTable  0x0209FF88  data
 *   ISS_SYS_GetBgmMode  0x0202B818  thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

typedef struct {
    u8   id;
    u8   pad[3];
    void (*enter)(void *);
    void (*leave)(void *);
} Entry;

extern const Entry ISS_SYS_ModeTable[];
struct Obj;
extern u8 ISS_SYS_GetBgmMode(struct Obj *o);

void ISS_SYS_SwitchMode(void *a)
{
    int v = ISS_SYS_GetBgmMode(a);
    int i;

    for (i = 0; i < 9; i++) {
        if (v != ISS_SYS_ModeTable[i].id && ISS_SYS_ModeTable[i].leave != 0) {
            ISS_SYS_ModeTable[i].leave(a);
        }
    }
    if (ISS_SYS_ModeTable[v].enter != 0) {
        ISS_SYS_ModeTable[v].enter(a);
    }
}
