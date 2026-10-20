/*
 * function: FLDMMDL_MOVE_GetFieldG3dMapHit
 * address: 0x02163E1C
 * packet: pkt_ov010_02163E1C
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   FLDMMDL_GetMmdlSys 0x0216D67C thumb ov010
 *   FLDMMDL_SysGetG3dMapper 0x0216D52C thumb ov010
 *   FIELD_G3D_MAPPER_QueryNearestHit 0x0218DAEC thumb ov021
 */

typedef unsigned short u16;
typedef struct { u16 a,b,c,d; int p,q; } E;
extern void *FLDMMDL_GetMmdlSys(void *);
typedef unsigned int   u32;
extern u32 FLDMMDL_SysGetG3dMapper(void *p);
extern int FIELD_G3D_MAPPER_QueryNearestHit(char *, char *, E *);
int FLDMMDL_MOVE_GetFieldG3dMapHit(void *a, char *b, E *c) { return FIELD_G3D_MAPPER_QueryNearestHit((char *)FLDMMDL_SysGetG3dMapper(FLDMMDL_GetMmdlSys(a)),b,c); }
