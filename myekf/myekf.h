#pragma once

#include "estimator_interface.h"

#if defined(CONFIG_EKF2_GNSS)
# include "yaw_estimator/EKFGSF_yaw.h"
#endif // CONFIG_EKF2_GNSS

#include "bias_estimator.hpp"
#include "height_bias_estimator.hpp"
#include "position_bias_estimator.hpp"

#include <ekf_derivation/generated/state.h>

#include <uORB/topics/estimator_aid_source1d.h>
#include <uORB/topics/estimator_aid_source2d.h>
#include <uORB/topics/estimator_aid_source3d.h>

#include "aid_sources/ZeroGyroUpdate.hpp"
#include "aid_sources/ZeroVelocityUpdate.hpp"

# include "aux_global_position.hpp"

enum class Likelihood { LOW, MEDIUM, HIGH };

class Myekf final : public EstimatorInterface
{
public:
	typedef matrix::Vector<float, State::size> VectorState;
	typedef matrix::SquareMatrix<float, State::size> SquareMatrixState;
	typedef matrix::SquareMatrix<float, 2> Matrix2f;

	Myekf() {
		reset();
	};

        virtual ~Myekf() = default;

        bool init(uint64_t timestamp) override;

	void print_status();

	bool update();

	const StateSample &state() const { return _state; }

private:
        void reset();
};
