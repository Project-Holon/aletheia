/*
 * function: DEMO3D_DATA_TaskFade
 * address: 0x021BF4C4
 * packet: pkt_ov203_021BF4C4
 * region: ov203
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   DEMO3D_DATA_IsCaptureDone 0x021BF7AC thumb ov203
 *   DEMO3D_DATA_CreateFade 0x021BF510 thumb ov203
 *   GAME_VERSION_Code 0x0209DF08 data a1
 */
extern const unsigned char GAME_VERSION_Code;
extern int DEMO3D_DATA_IsCaptureDone(char *,int);
extern void DEMO3D_DATA_CreateFade(char *,int,int,int,int,int,int);
void DEMO3D_DATA_TaskFade(char *p,int unused,int *record)
{
    int a,b,c;
    if(record[0]==0xFF || record[0]==GAME_VERSION_Code) {
        a=DEMO3D_DATA_IsCaptureDone(p,record[4]);b=DEMO3D_DATA_IsCaptureDone(p,record[5]);c=DEMO3D_DATA_IsCaptureDone(p,record[6]);
        DEMO3D_DATA_CreateFade(p,record[1],record[2],record[3],a,b,c);
    }
}
