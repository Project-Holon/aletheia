/*
 * function: func_021AE050
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
 *   func_02047910  0x02047910  arm
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

extern int func_02047910(void *a, int idx, int amount);

void func_021AE050(void *self, Arg *arg)
{
    Owner *owner = arg->owner;
    func_02047910(owner->obj, 0, FX_F32_TO_FX32(arg->n * 2 + 1));
}
