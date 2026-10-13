/*
 * function: FLDEFF_FISHING_Update
 * address:  0x021AE050
 * packet:   pkt_ov021_021AE050
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Set channel 0 of the object at +0xC of *arg->owner to (2*arg->n + 1)
 * converted through FX_F32_TO_FX32.
 *
 * symbols:
 *   G3D_SYSTEM_LoopObjectAnimeFrame  0x02047910  arm
 *   _fflt          0x0209BDBC  arm
 *   _fadd          0x0209C95C  arm
 *   _fsub          0x0209CB8C  arm
 *   _ffix          0x0209C494  arm
 */

typedef struct Owner {
    char pad00[0xC];
    void *obj;
} Owner;

typedef struct Arg {
    Owner *owner;
    unsigned short n;
} Arg;

#define FX_F32_TO_FX32(x) \
    ((int)(((x) > 0) ? (x) * 4096 + 0.5f : (x) * 4096 - 0.5f))

extern int G3D_SYSTEM_LoopObjectAnimeFrame(void *a, int idx, int amount);

void FLDEFF_FISHING_Update(void *self, Arg *arg)
{
    Owner *owner = arg->owner;
    G3D_SYSTEM_LoopObjectAnimeFrame(owner->obj, 0, FX_F32_TO_FX32(arg->n * 2 + 1));
}
