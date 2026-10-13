/*
 * function: DWCi_ScCleanupRootCAList
 * address:  0x021DEFC4
 * packet:   pkt_021DEFC4
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   wsGetServiceUrl  0x021E22E4  arm  ov175
 *   scCleanupServiceUrl  0x021DFE20  arm  ov175
 *   DWC_GHTTPCleanupRootCAList  0x021BF540  arm  ov114
 *
 * Build/teardown pair: wsGetServiceUrl (ov175) and scCleanupServiceUrl, each
 *  *  separated by a 0x021BF540 (ov114) step -- the overlay re-arms its state
 *  *  between the two halves.
 */

typedef signed int     s32;
extern s32 wsGetServiceUrl(void);
extern int DWC_GHTTPCleanupRootCAList(void);
extern void scCleanupServiceUrl(void);

void DWCi_ScCleanupRootCAList(void)
{
    wsGetServiceUrl();
    DWC_GHTTPCleanupRootCAList();
    scCleanupServiceUrl();
    DWC_GHTTPCleanupRootCAList();
}

