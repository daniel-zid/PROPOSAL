
/******************************************************************************
 *                                                                            *
 * This file is part of the simulation tool PROPOSAL.                         *
 *                                                                            *
 * Copyright (C) 2017 TU Dortmund University, Department of Physics,          *
 *                    Chair Experimental Physics 5b                           *
 *                                                                            *
 * This software may be modified and distributed under the terms of a         *
 * modified GNU Lesser General Public Licence version 3 (LGPL),               *
 * copied verbatim in the file "LICENSE".                                     *
 *                                                                            *
 * Modifcations to the LGPL License:                                          *
 *                                                                            *
 *      1. The user shall acknowledge the use of PROPOSAL by citing the       *
 *         following reference:                                               *
 *                                                                            *
 *         J.H. Koehne et al.  Comput.Phys.Commun. 184 (2013) 2070-2090 DOI:  *
 *         10.1016/j.cpc.2013.04.001                                          *
 *                                                                            *
 *      2. The user should report any bugs/errors or improvments to the       *
 *         current maintainer of PROPOSAL or open an issue on the             *
 *         GitHub webpage                                                     *
 *                                                                            *
 *         "https://github.com/tudo-astroparticlephysics/PROPOSAL"            *
 *                                                                            *
 ******************************************************************************/


#pragma once

#include "PROPOSAL/crossection/CrossSectionInterpolant.h"

namespace PROPOSAL {

class EpairProduction;

class EpairInterpolant : public CrossSectionInterpolant
{
public:
    EpairInterpolant(const EpairProduction&, std::shared_ptr<const EnergyCutSettings>, const InterpolationDef&);
    //EpairInterpolant(const EpairInterpolant&);
    virtual ~EpairInterpolant();

    //CrossSection* clone() const { return new EpairInterpolant(*this); }

    // ----------------------------------------------------------------- //
    // Public methods
    // ----------------------------------------------------------------- //

    double CalculatedEdx(double energy);
    double FunctionToBuildDNdxInterpolant2D(double energy, double v, Integral&, int component) override;

protected:
    virtual bool compare(const CrossSection&) const;

private:
    std::function<double(double, double)> functiondNdxIntegral;
    std::unordered_map<std::string, bool> interpolateDifferentialCrossSection = {
            {"EpairKelnerKokoulinPetrukhin",true},
            {"SandrockSoedingreksoRhode",true}
    };
    double FunctionToBuildDiffCrossSectionInterpolant(double energy, double v, int component);
    double InterpolatedCrossSection(double energy, double v);
    void InitializeDifferentialCrossSectionInterpolation(const InterpolationDef& def);
    InterpolantVec interpolant_;
};

} // namespace PROPOSAL
