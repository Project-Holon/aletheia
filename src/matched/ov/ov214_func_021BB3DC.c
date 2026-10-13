/*
 * function: func_021BB3DC
 * address: 0x021BB3DC
 * packet: pkt_ov214_021BB3DC
 * region: ov214
 * compiler: 1.1p1
 * flags: -O4,p
 * isa: thumb
 * lang: c99
 * status: EXACT
 * symbols:
 *   G3D_SYSTEM_Init 0x02046440 arm
 *   G3D_CAMERA_Create 0x02048A24 arm
 *   func_021BB0D4 0x021BB0D4 thumb ov214
 *   dims 0x020A1EB8 data
 *   vec1 0x021BB524 data a4
 *   vec2 0x021BB518 data ov214
 *   vec3 0x021BB530 data ov214
 * Heap forwarded without truncation: widen legacy s16/u16 externs.
 */
typedef unsigned int u32;
typedef signed short s16;
typedef unsigned short u16;
struct Vec3 { u32 x,y,z; };
extern const char dims[];
extern struct Vec3 vec1,vec2,vec3;
extern void func_021BB0D4(void);
extern void G3D_SYSTEM_Init(u32,u32,u32,u32,u16,u32,void (*)(void));
extern u32 *G3D_CAMERA_Create(u32,u32,u32,u32,u32,u32,u32,u32,struct Vec3 *,struct Vec3 *,struct Vec3 *,u32);
void func_021BB3DC(u32 **out,u32 heap)
{
    G3D_SYSTEM_Init(0,1,0,1,0,heap,func_021BB0D4);
    *out=G3D_CAMERA_Create(0,*(s16 *)(dims+12),*(s16 *)(dims+14),0x1555,0,4096,0x400000,0,&vec1,&vec2,&vec3,heap);
}
