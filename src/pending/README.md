Byte-correct but MATCH-capped sources.

Every concrete byte of these functions reproduces the original; the entry
is capped at MATCH because one or more relocation targets have no witness
outside the compared range (see the honesty rule in docs/MATCHING.md).
They are parked here, OUT of the manifest, until coverage growth or an
attestation extension supplies an outside witness. The manifest and the
build must contain EXACT entries only.
