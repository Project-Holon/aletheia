/*
 * function: func_021BE508
 * address: 0x021BE508
 * packet: pkt_ov203_021BE508
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: 46-byte body plus two-byte alignment at 0x021BE536.
 * blocked: ARM9 0x02048BA8 and 0x02048BBC; existing matched unit_02048AD0.c contains their bodies but omits both from function:.
 * spelling: loads repeated in explicit branch arms reproduce cmp-before-base-load; shared-base and offset ternary differ.
 * blocker:
 *   0x02048BA8 ARM EXACT, dsi/1.1p1 -O4,p, verified without --region:
 *   void G3D_CAMERA_SetNearClipAlt(struct Light *p,u32 v) { *(u32 *)((char *)p+4)=v; }
 *   0x02048BBC ARM EXACT, dsi/1.1p1 -O4,p, verified without --region:
 *   void G3D_CAMERA_SetFarClipAlt(struct Light *p,u32 v) { *(u32 *)((char *)p+8)=v; }
 * symbols:
 *   func_0204EA38 0x0204EA38 arm
 *   G3D_CAMERA_SetNearClipAlt 0x02048BA8 arm
 *   G3D_CAMERA_SetFarClipAlt 0x02048BBC arm
 */
typedef unsigned int u32;
struct Light;
extern u32 func_0204EA38(void);
extern void G3D_CAMERA_SetNearClipAlt(struct Light *,u32);
extern void G3D_CAMERA_SetFarClipAlt(struct Light *,u32);
void func_021BE508(char *p,struct Light *q)
{
    int x;
    if(func_0204EA38()==0)x=*(short *)(*(char **)(p+0x74)+0x20);
    else x=*(short *)(*(char **)(p+0x74)+0x22);
    G3D_CAMERA_SetNearClipAlt(q,x+*(u32 *)(p+0x24));
    G3D_CAMERA_SetFarClipAlt(q,x+*(u32 *)(p+0x28));
}
