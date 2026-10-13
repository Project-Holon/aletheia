/*
 * function: WIFICLUB_HasNewClientAid
 * address:  0x021BF050
 * packet:   pkt_021B95A0
 * region:   ov099
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 *
 * symbols:
 *   DWC_RAP_GetNewClientAid  0x02156B8C  thumb  ov009
 * True unless the arm9 predicate answers -1.
 *
 * Unblocked by matching DWC_RAP_GetNewClientAid (ov009, EXACT): the +0002 call site now
 * attests as `matched`.  The old `ov172` hint was simply wrong -- 0x02156B8C
 * is not inside ov172's window; the address is coherent Thumb code in ov009
 * (ov010 holds the tail of another function there).
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/WIFICLUB_HasNewClientAid.c --func WIFICLUB_HasNewClientAid --addr 0x021BF050 \n    --region ov099 --thumb --cc dsi/1.1p1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned long  u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed long    s32;
typedef int BOOL;

extern int DWC_RAP_GetNewClientAid(void);

BOOL WIFICLUB_HasNewClientAid(char *p)
{
    if (DWC_RAP_GetNewClientAid() != -1) {
        return 1;
    }

    return 0;
}
