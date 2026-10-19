#ifndef OV114_DWC_SVL_TYPES_H
#define OV114_DWC_SVL_TYPES_H
/*
 * Result of the service locator (SVL) token request: host and token for the
 * download server.  Owned here because ov114/dwc_nd_types.h cannot be
 * included from ov125 (it pulls its sibling dwci_nd_types.h by a relative
 * name), so ov125/gds_rap_types.h includes this minimal header instead.
 */
#include "../sdk_dwc.h"

#endif
