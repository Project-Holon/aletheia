/*
 * function: SCRCMD_PROC_LookupTableValue
 * address: 0x0215B488
 * packet: pkt_ov010_0215B488
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * interfaces: Lookup results used despite legacy void forwarders; observed inputs retained.
 * symbols:
 *   SCRIPT_WORK_ReadWorkValue 0x02159B10 thumb ov010
 *   SCRIPT_WORK_ReadWorkPointer 0x02159AE8 thumb ov010
 *   sScrcmdLookupTable 0x02171170 data a2
 */
typedef unsigned short u16;
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *,void *);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern const u16 sScrcmdLookupTable[];
int SCRCMD_PROC_LookupTableValue(int a,int b)
{
    int k = SCRIPT_WORK_ReadWorkValue((void *)a,(void *)b);
    u16 *out = SCRIPT_WORK_ReadWorkPointer((void *)a,(void *)b);
    *out = sScrcmdLookupTable[k];
    return 0;
}
