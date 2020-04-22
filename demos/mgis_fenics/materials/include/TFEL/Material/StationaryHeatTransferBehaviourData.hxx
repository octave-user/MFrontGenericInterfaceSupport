/*!
* \file   TFEL/Material/StationaryHeatTransferBehaviourData.hxx
* \brief  this file implements the StationaryHeatTransferBehaviourData class.
*         File generated by tfel version 3.4.0-dev
* \author Thomas Helfer
* \date   15 / 02 / 2019
 */

#ifndef LIB_TFELMATERIAL_STATIONARYHEATTRANSFER_BEHAVIOUR_DATA_HXX
#define LIB_TFELMATERIAL_STATIONARYHEATTRANSFER_BEHAVIOUR_DATA_HXX

#include<limits>
#include<string>
#include<sstream>
#include<iostream>
#include<stdexcept>
#include<algorithm>

#include"TFEL/Raise.hxx"
#include"TFEL/PhysicalConstants.hxx"
#include"TFEL/Config/TFELConfig.hxx"
#include"TFEL/Config/TFELTypes.hxx"
#include"TFEL/Metaprogramming/StaticAssert.hxx"
#include"TFEL/TypeTraits/IsFundamentalNumericType.hxx"
#include"TFEL/TypeTraits/IsReal.hxx"
#include"TFEL/Math/General/IEEE754.hxx"
#include"TFEL/Math/stensor.hxx"
#include"TFEL/Math/Stensor/StensorView.hxx"
#include"TFEL/Math/Stensor/StensorConceptIO.hxx"
#include"TFEL/Math/tmatrix.hxx"
#include"TFEL/Math/Matrix/tmatrixIO.hxx"
#include"TFEL/Math/st2tost2.hxx"
#include"TFEL/Math/ST2toST2/ST2toST2ConceptIO.hxx"
#include"TFEL/Math/ST2toST2/ST2toST2View.hxx"
#include"TFEL/Math/tensor.hxx"
#include"TFEL/Math/Tensor/TensorConceptIO.hxx"
#include"TFEL/Math/t2tot2.hxx"
#include"TFEL/Math/T2toT2/T2toT2ConceptIO.hxx"
#include"TFEL/Math/t2tost2.hxx"
#include"TFEL/Math/T2toST2/T2toST2ConceptIO.hxx"
#include"TFEL/Math/st2tot2.hxx"
#include"TFEL/Math/ST2toT2/ST2toT2ConceptIO.hxx"
#include"TFEL/Math/ST2toST2/ConvertToTangentModuli.hxx"
#include"TFEL/Math/ST2toST2/ConvertSpatialModuliToKirchhoffJaumanRateModuli.hxx"
#include"TFEL/Material/FiniteStrainBehaviourTangentOperator.hxx"
#include"TFEL/Math/T2toT2/T2toT2View.hxx"
#include"TFEL/Math/T2toST2/T2toST2View.hxx"
#include"TFEL/Math/ST2toT2/ST2toT2View.hxx"
#include"TFEL/Material/ModellingHypothesis.hxx"

#include "MFront/GenericBehaviour/State.hxx"
#include "MFront/GenericBehaviour/BehaviourData.hxx"
namespace tfel{

namespace material{

//! \brief forward declaration
template<ModellingHypothesis::Hypothesis hypothesis,typename,bool>
class StationaryHeatTransferBehaviourData;

//! \brief forward declaration
template<ModellingHypothesis::Hypothesis hypothesis,typename Type,bool use_qt>
class StationaryHeatTransferIntegrationData;

//! \brief forward declaration
template<ModellingHypothesis::Hypothesis hypothesis,typename Type>
std::ostream&
 operator <<(std::ostream&,const StationaryHeatTransferBehaviourData<hypothesis,Type,false>&);

template<ModellingHypothesis::Hypothesis hypothesis,typename Type>
class StationaryHeatTransferBehaviourData<hypothesis,Type,false>
{

static constexpr unsigned short N = ModellingHypothesisToSpaceDimension<hypothesis>::value;
TFEL_STATIC_ASSERT(N==1||N==2||N==3);
TFEL_STATIC_ASSERT(tfel::typetraits::IsFundamentalNumericType<Type>::cond);
TFEL_STATIC_ASSERT(tfel::typetraits::IsReal<Type>::cond);

friend std::ostream& operator<< <>(std::ostream&,const StationaryHeatTransferBehaviourData&);

/* integration data is declared friend to access   driving variables at the beginning of the time step */
friend class StationaryHeatTransferIntegrationData<hypothesis,Type,false>;

static constexpr unsigned short TVectorSize = N;
typedef tfel::math::StensorDimeToSize<N> StensorDimeToSize;
static constexpr unsigned short StensorSize = StensorDimeToSize::value;
typedef tfel::math::TensorDimeToSize<N> TensorDimeToSize;
static constexpr unsigned short TensorSize = TensorDimeToSize::value;

using ushort =  unsigned short;
using Types = tfel::config::Types<N,Type,false>;
using real                = typename Types::real;
using time                = typename Types::time;
using length              = typename Types::length;
using frequency           = typename Types::frequency;
using stress              = typename Types::stress;
using strain              = typename Types::strain;
using strainrate          = typename Types::strainrate;
using stressrate          = typename Types::stressrate;
using temperature         = typename Types::temperature;
using thermalexpansion    = typename Types::thermalexpansion;
using thermalconductivity = typename Types::thermalconductivity;
using massdensity         = typename Types::massdensity;
using energydensity         = typename Types::energydensity;
using TVector             = typename Types::TVector;
using Stensor             = typename Types::Stensor;
using Stensor4            = typename Types::Stensor4;
using FrequencyStensor    = typename Types::FrequencyStensor;
using ForceTVector        = typename Types::ForceTVector;
using StressStensor       = typename Types::StressStensor;
using StressRateStensor   = typename Types::StressRateStensor;
using DisplacementTVector = typename Types::DisplacementTVector;
using StrainStensor       = typename Types::StrainStensor;
using StrainRateStensor   = typename Types::StrainRateStensor;
using StiffnessTensor     = typename Types::StiffnessTensor;
using Tensor              = typename Types::Tensor;
using FrequencyTensor     = typename Types::FrequencyTensor;
using StressTensor        = typename Types::StressTensor;
using ThermalExpansionCoefficientTensor = typename Types::ThermalExpansionCoefficientTensor;
using DeformationGradientTensor         = typename Types::DeformationGradientTensor;
using DeformationGradientRateTensor     = typename Types::DeformationGradientRateTensor;
using TemperatureGradient = typename Types::TemperatureGradient;
using HeatFlux = typename Types::HeatFlux;
using TangentOperator   = tfel::math::tvector<(TVectorSize)*(TVectorSize)+(TVectorSize)*(1),real>;
using PhysicalConstants = tfel::PhysicalConstants<real>;

protected:

TemperatureGradient tum_2207__T;

HeatFlux j;


temperature T;

public:

/*!
* \brief Default constructor
*/
StationaryHeatTransferBehaviourData()
{}

/*!
* \brief copy constructor
*/
StationaryHeatTransferBehaviourData(const StationaryHeatTransferBehaviourData& src)
: tum_2207__T(src.tum_2207__T),
j(src.j),
T(src.T)
{}

/*
 * \brief constructor for the Generic interface
 * \param[in] mgb_d: behaviour data
 */
StationaryHeatTransferBehaviourData(const mfront::gb::BehaviourData& mgb_d)
: T(mgb_d.s0.external_state_variables[0])
{
}


/*
* \brief Assignement operator
*/
StationaryHeatTransferBehaviourData&
operator=(const StationaryHeatTransferBehaviourData& src){
this->tum_2207__T = src.tum_2207__T;
this->j = src.j;
this->T = src.T;
return *this;
}

void exportStateData(mfront::gb::State& mbg_s1) const
{
using namespace tfel::math;
tfel::fsalgo::copy<TVectorSize>::exe(this->j.begin(), mbg_s1.thermodynamic_forces);
} // end of exportStateData

}; // end of StationaryHeatTransferBehaviourDataclass

template<ModellingHypothesis::Hypothesis hypothesis,typename Type>
std::ostream&
operator <<(std::ostream& os,const StationaryHeatTransferBehaviourData<hypothesis,Type,false>& b)
{
os << "∇T : " << b.tum_2207__T << '\n';
os << "j : " << b.j << '\n';
os << "T : " << b.T << '\n';
return os;
}

} // end of namespace material

} // end of namespace tfel

#endif /* LIB_TFELMATERIAL_STATIONARYHEATTRANSFER_BEHAVIOUR_DATA_HXX */
