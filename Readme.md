# Matrix Library - A Heuristic Oriented Library

This matrix library takes a different approach toward matrix manipulation than many others.  It does so by characterizing the matrices as they are loaded or generated.  The few CPU cycles needed to discern whether the matrix is square, an identity matrix, diagonal, etc... means that operations called, such as multiplication, can use algorithms optimized for the type of matrix.

The library seeks to minimize memory footprint from first principles. Matrix representations reduce to the smallest encoding when initializing (unless directed otherwise).

If optimizations through characterization heuristics and encoding happen automatically upon use, then layers placed upon the use of this library need not be as concerned with *premature optimization*.

