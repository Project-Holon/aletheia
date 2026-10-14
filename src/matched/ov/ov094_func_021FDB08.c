/*
 * function: BTLV_EFFVM_DeleteEmitter
 * address:  0x021FDB08
 * packet:   pkt_ov094_021FDB08
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PARTICLE_GetWorkBase  0x02051640  arm
 *   PARTICLE_DeleteSystem  0x02050DB8  arm
 *   func_020307B0  0x020307B0  arm
 */
typedef unsigned char  u8;
extern void *PARTICLE_GetWorkBase(char *p);
extern void PARTICLE_DeleteSystem(u8 *p);
typedef unsigned int   u32;
extern u32 func_020307B0(void *p);

void BTLV_EFFVM_DeleteEmitter(void *p)
{
    void *q = PARTICLE_GetWorkBase(p);

    PARTICLE_DeleteSystem(p);
    func_020307B0(q);
}
