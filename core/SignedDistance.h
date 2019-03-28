
#pragma once

namespace msdfgen {

/// Represents a signed distance and alignment, which together can be compared to uniquely determine the closest edge segment.
class SignedDistance {

public:
	// Certain platforms apparently don't like INFINITE, So, renamed to INFINITE_SIGNED_DISTANCE
    static const SignedDistance INFINITE_SIGNED_DISTANCE;

    double distance;
    double dot;

    SignedDistance();
    SignedDistance(double dist, double d);

    friend bool operator<(SignedDistance a, SignedDistance b);
    friend bool operator>(SignedDistance a, SignedDistance b);
    friend bool operator<=(SignedDistance a, SignedDistance b);
    friend bool operator>=(SignedDistance a, SignedDistance b);

};

}
