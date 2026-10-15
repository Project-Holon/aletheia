/*
 * unit: yes
 * function: func_021BE148,func_021BE150,func_021BE158
 * address: 0x021BE148
 * packet: pkt_ov203_021BE148
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * leaf: solely blocks assigned 021BDF24; parent cleared ownership.
 * extent: three 8-byte wrappers; ends at peer-owned 021BE160, which is excluded.
 * symbols:
 *   G3D_SYSTEM_DrawEnd 0x02047970 arm
 *   DOUBLE3DDISP_Delete 0x0204EA64 arm
 *   G3D_CAMERA_Delete 0x02048AC4 arm
 */
extern void G3D_SYSTEM_DrawEnd(void);
extern void DOUBLE3DDISP_Delete(void);
typedef unsigned int   u32;
extern u32 G3D_CAMERA_Delete(void *ptr);
void func_021BE148(void *p){G3D_SYSTEM_DrawEnd();}
void func_021BE150(void){DOUBLE3DDISP_Delete();}
void func_021BE158(void *p){G3D_CAMERA_Delete(p);}
