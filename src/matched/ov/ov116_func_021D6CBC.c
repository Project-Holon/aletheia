/*
 * function: WIFI_BSUBWAY_StartProfileUpload
 * address: 0x021D6CBC
 * packet: pkt_ov116_021D6CBC
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * blocker: ARM9 02012EF0 and 02012EFC lack an outside code witness.
 * blocker: 0x02012EF0 verified EXACT in 12EF0-r1.log (Thumb, dsi/1.1p1 -O4,p).
 *   extern int func_020071CC(void *,int);
 *   int GAME_DATA_GetSaveBlock3A(void **p) { return func_020071CC(*p,58); }
 * blocker: 0x02012EFC verified EXACT in 12EFC-r1.log (Thumb, dsi/1.1p1 -O4,p).
 *   extern int func_020071CC(void *,int);
 *   int GAME_DATA_GetSaveBlock3B(void **p) { return func_020071CC(*p,59); }
 * symbols:
 *   GAME_DATA_GetSaveBlock3B 0x02012EFC thumb
 *   GAME_DATA_GetSaveBlock3A 0x02012EF0 thumb
 *   NHTTP_RAP_InitTrainerInfo 0x021B9B00 thumb ov114
 *   DPW_BT_SetProfileAsync 0x021C9744 arm ov114
 *   WIFI_BSUBWAY_AsyncReset 0x021D70E4 thumb ov116
 *   WIFI_BSUBWAY_BuildProfile 0x021D6D40 thumb ov116
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb  arm9
 */
typedef unsigned char u8;
struct Big;
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *GAME_DATA_GetSaveBlock3B(void **p);
extern void *GAME_DATA_GetSaveBlock3A(void **p);
extern void NHTTP_RAP_InitTrainerInfo(u8 *,int);
extern void DPW_BT_SetProfileAsync(unsigned char *p, unsigned x);
extern void WIFI_BSUBWAY_AsyncReset(u8 *);
extern void WIFI_BSUBWAY_BuildProfile(u8 *p, void *save, void *idx);
void WIFI_BSUBWAY_StartProfileUpload(u8 *p,void *q,u8 *r) {
    int a,b,c;
    GAME_DATA_GetSaveControl(q);
    a = (int)GAME_DATA_GetSaveBlock3B(q);
    b = (int)GAME_DATA_GetSaveBlock3A(q);
    c = *(int *)(p+0x218);
    NHTTP_RAP_InitTrainerInfo(p+4,c);
    DPW_BT_SetProfileAsync(p+4,(unsigned int)(p+0x68));
    WIFI_BSUBWAY_AsyncReset(r);
    WIFI_BSUBWAY_BuildProfile(p+0x70,q,(void *)c);
    *(int *)(p+0x160)=a;
    *(int *)(p+0x164)=b;
}
