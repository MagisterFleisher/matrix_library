# Matrix Library - A Heuristic Oriented Library

This matrix library takes a different approach toward matrix manipulation than many others.  It does so by characterizing the matrices as they are loaded or generated.  The few CPU cycles needed to discern whether the matrix is square, an identity matrix, diagonal, etc... means that operations called, such as multiplication, can use algorithms optimized for the type of matrix.

The library seeks to minimize memory footprint from first principles. Matrix representations reduce to the smallest encoding when initializing (unless directed otherwise).

If optimizations through characterization heuristics and encoding happen automatically upon use, then layers placed upon the use of this library need not be as concerned with *premature optimization*.


## Intent of project

This library is an educational project by the repository owner.  It will be the basis for a machine learning library.

## State of Development

The library only has linux development in mind.  Future development may include versions specifically for OS X and/or Windows.

This library is currently be developed only by the owner.  However, feel free to use the code.  But give credit where credit is due, please.

## Plans for Future Development

The next stage of development for this library would be to make it a front end for an optimized BLAS library.  The owner of the repository plans on using the BLIS library: https://github.com/flame/blis

Another aspect of this library that deserves special consideration would be implementing sparse matrix representation and optimizations.