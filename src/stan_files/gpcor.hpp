/*
    motifator is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    motifator is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with motifator.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef MODELS_HPP
#define MODELS_HPP
#define STAN__SERVICES__COMMAND_HPP
#include <rstan/rstaninc.hpp>
// Code generated by Stan version 2.17.0

#include <stan/model/model_header.hpp>

namespace model_gpcor_namespace {

using std::istream;
using std::string;
using std::stringstream;
using std::vector;
using stan::io::dump;
using stan::math::lgamma;
using stan::model::prob_grad;
using namespace stan::math;

typedef Eigen::Matrix<double,Eigen::Dynamic,1> vector_d;
typedef Eigen::Matrix<double,1,Eigen::Dynamic> row_vector_d;
typedef Eigen::Matrix<double,Eigen::Dynamic,Eigen::Dynamic> matrix_d;

static int current_statement_begin__;

stan::io::program_reader prog_reader__() {
    stan::io::program_reader reader;
    reader.add_event(0, 0, "start", "model_gpcor");
    reader.add_event(62, 62, "end", "model_gpcor");
    return reader;
}

#include <meta_header.hpp>
 class model_gpcor : public prob_grad {
private:
    int X;
    int N;
    int NW;
    double mean_p;
    double mean_p_sd;
    double target_i;
    double target_i_sd;
    matrix_d D;
    vector<vector<int> > A;
    double moran_i_ratio;
public:
    model_gpcor(stan::io::var_context& context__,
        std::ostream* pstream__ = 0)
        : prob_grad(0) {
        ctor_body(context__, 0, pstream__);
    }

    model_gpcor(stan::io::var_context& context__,
        unsigned int random_seed__,
        std::ostream* pstream__ = 0)
        : prob_grad(0) {
        ctor_body(context__, random_seed__, pstream__);
    }

    void ctor_body(stan::io::var_context& context__,
                   unsigned int random_seed__,
                   std::ostream* pstream__) {
        boost::ecuyer1988 base_rng__ =
          stan::services::util::create_rng(random_seed__, 0);
        (void) base_rng__;  // suppress unused var warning

        current_statement_begin__ = -1;

        static const char* function__ = "model_gpcor_namespace::model_gpcor";
        (void) function__;  // dummy to suppress unused var warning
        size_t pos__;
        (void) pos__;  // dummy to suppress unused var warning
        std::vector<int> vals_i__;
        std::vector<double> vals_r__;
        double DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning

        // initialize member variables
        try {
            current_statement_begin__ = 3;
            context__.validate_dims("data initialization", "X", "int", context__.to_vec());
            X = int(0);
            vals_i__ = context__.vals_i("X");
            pos__ = 0;
            X = vals_i__[pos__++];
            current_statement_begin__ = 4;
            context__.validate_dims("data initialization", "N", "int", context__.to_vec());
            N = int(0);
            vals_i__ = context__.vals_i("N");
            pos__ = 0;
            N = vals_i__[pos__++];
            current_statement_begin__ = 5;
            context__.validate_dims("data initialization", "NW", "int", context__.to_vec());
            NW = int(0);
            vals_i__ = context__.vals_i("NW");
            pos__ = 0;
            NW = vals_i__[pos__++];
            current_statement_begin__ = 6;
            context__.validate_dims("data initialization", "mean_p", "double", context__.to_vec());
            mean_p = double(0);
            vals_r__ = context__.vals_r("mean_p");
            pos__ = 0;
            mean_p = vals_r__[pos__++];
            current_statement_begin__ = 7;
            context__.validate_dims("data initialization", "mean_p_sd", "double", context__.to_vec());
            mean_p_sd = double(0);
            vals_r__ = context__.vals_r("mean_p_sd");
            pos__ = 0;
            mean_p_sd = vals_r__[pos__++];
            current_statement_begin__ = 8;
            context__.validate_dims("data initialization", "target_i", "double", context__.to_vec());
            target_i = double(0);
            vals_r__ = context__.vals_r("target_i");
            pos__ = 0;
            target_i = vals_r__[pos__++];
            current_statement_begin__ = 9;
            context__.validate_dims("data initialization", "target_i_sd", "double", context__.to_vec());
            target_i_sd = double(0);
            vals_r__ = context__.vals_r("target_i_sd");
            pos__ = 0;
            target_i_sd = vals_r__[pos__++];
            current_statement_begin__ = 10;
            validate_non_negative_index("D", "N", N);
            validate_non_negative_index("D", "N", N);
            context__.validate_dims("data initialization", "D", "matrix_d", context__.to_vec(N,N));
            validate_non_negative_index("D", "N", N);
            validate_non_negative_index("D", "N", N);
            D = matrix_d(static_cast<Eigen::VectorXd::Index>(N),static_cast<Eigen::VectorXd::Index>(N));
            vals_r__ = context__.vals_r("D");
            pos__ = 0;
            size_t D_m_mat_lim__ = N;
            size_t D_n_mat_lim__ = N;
            for (size_t n_mat__ = 0; n_mat__ < D_n_mat_lim__; ++n_mat__) {
                for (size_t m_mat__ = 0; m_mat__ < D_m_mat_lim__; ++m_mat__) {
                    D(m_mat__,n_mat__) = vals_r__[pos__++];
                }
            }
            current_statement_begin__ = 11;
            validate_non_negative_index("A", "NW", NW);
            validate_non_negative_index("A", "2", 2);
            context__.validate_dims("data initialization", "A", "int", context__.to_vec(NW,2));
            validate_non_negative_index("A", "NW", NW);
            validate_non_negative_index("A", "2", 2);
            A = std::vector<std::vector<int> >(NW,std::vector<int>(2,int(0)));
            vals_i__ = context__.vals_i("A");
            pos__ = 0;
            size_t A_limit_1__ = 2;
            for (size_t i_1__ = 0; i_1__ < A_limit_1__; ++i_1__) {
                size_t A_limit_0__ = NW;
                for (size_t i_0__ = 0; i_0__ < A_limit_0__; ++i_0__) {
                    A[i_0__][i_1__] = vals_i__[pos__++];
                }
            }
            current_statement_begin__ = 12;
            context__.validate_dims("data initialization", "moran_i_ratio", "double", context__.to_vec());
            moran_i_ratio = double(0);
            vals_r__ = context__.vals_r("moran_i_ratio");
            pos__ = 0;
            moran_i_ratio = vals_r__[pos__++];

            // validate, data variables
            current_statement_begin__ = 3;
            current_statement_begin__ = 4;
            current_statement_begin__ = 5;
            current_statement_begin__ = 6;
            current_statement_begin__ = 7;
            current_statement_begin__ = 8;
            current_statement_begin__ = 9;
            current_statement_begin__ = 10;
            current_statement_begin__ = 11;
            current_statement_begin__ = 12;
            // initialize data variables


            // validate transformed data

            // validate, set parameter ranges
            num_params_r__ = 0U;
            param_ranges_i__.clear();
            current_statement_begin__ = 18;
            validate_non_negative_index("y", "N", N);
            num_params_r__ += N;
            current_statement_begin__ = 19;
            ++num_params_r__;
            current_statement_begin__ = 20;
            ++num_params_r__;
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
    }

    ~model_gpcor() { }


    void transform_inits(const stan::io::var_context& context__,
                         std::vector<int>& params_i__,
                         std::vector<double>& params_r__,
                         std::ostream* pstream__) const {
        stan::io::writer<double> writer__(params_r__,params_i__);
        size_t pos__;
        (void) pos__; // dummy call to supress warning
        std::vector<double> vals_r__;
        std::vector<int> vals_i__;

        if (!(context__.contains_r("y")))
            throw std::runtime_error("variable y missing");
        vals_r__ = context__.vals_r("y");
        pos__ = 0U;
        validate_non_negative_index("y", "N", N);
        context__.validate_dims("initialization", "y", "vector_d", context__.to_vec(N));
        vector_d y(static_cast<Eigen::VectorXd::Index>(N));
        for (int j1__ = 0U; j1__ < N; ++j1__)
            y(j1__) = vals_r__[pos__++];
        try {
            writer__.vector_lub_unconstrain(0,1,y);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable y: ") + e.what());
        }

        if (!(context__.contains_r("sigma")))
            throw std::runtime_error("variable sigma missing");
        vals_r__ = context__.vals_r("sigma");
        pos__ = 0U;
        context__.validate_dims("initialization", "sigma", "double", context__.to_vec());
        double sigma(0);
        sigma = vals_r__[pos__++];
        try {
            writer__.scalar_lb_unconstrain(0,sigma);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable sigma: ") + e.what());
        }

        if (!(context__.contains_r("rho")))
            throw std::runtime_error("variable rho missing");
        vals_r__ = context__.vals_r("rho");
        pos__ = 0U;
        context__.validate_dims("initialization", "rho", "double", context__.to_vec());
        double rho(0);
        rho = vals_r__[pos__++];
        try {
            writer__.scalar_lb_unconstrain(0,rho);
        } catch (const std::exception& e) { 
            throw std::runtime_error(std::string("Error transforming variable rho: ") + e.what());
        }

        params_r__ = writer__.data_r();
        params_i__ = writer__.data_i();
    }

    void transform_inits(const stan::io::var_context& context,
                         Eigen::Matrix<double,Eigen::Dynamic,1>& params_r,
                         std::ostream* pstream__) const {
      std::vector<double> params_r_vec;
      std::vector<int> params_i_vec;
      transform_inits(context, params_i_vec, params_r_vec, pstream__);
      params_r.resize(params_r_vec.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r(i) = params_r_vec[i];
    }


    template <bool propto__, bool jacobian__, typename T__>
    T__ log_prob(vector<T__>& params_r__,
                 vector<int>& params_i__,
                 std::ostream* pstream__ = 0) const {

        T__ DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning

        T__ lp__(0.0);
        stan::math::accumulator<T__> lp_accum__;

        try {
            // model parameters
            stan::io::reader<T__> in__(params_r__,params_i__);

            Eigen::Matrix<T__,Eigen::Dynamic,1>  y;
            (void) y;  // dummy to suppress unused var warning
            if (jacobian__)
                y = in__.vector_lub_constrain(0,1,N,lp__);
            else
                y = in__.vector_lub_constrain(0,1,N);

            T__ sigma;
            (void) sigma;  // dummy to suppress unused var warning
            if (jacobian__)
                sigma = in__.scalar_lb_constrain(0,lp__);
            else
                sigma = in__.scalar_lb_constrain(0);

            T__ rho;
            (void) rho;  // dummy to suppress unused var warning
            if (jacobian__)
                rho = in__.scalar_lb_constrain(0,lp__);
            else
                rho = in__.scalar_lb_constrain(0);


            // transformed parameters
            current_statement_begin__ = 24;
            validate_non_negative_index("K", "N", N);
            validate_non_negative_index("K", "N", N);
            Eigen::Matrix<T__,Eigen::Dynamic,Eigen::Dynamic>  K(static_cast<Eigen::VectorXd::Index>(N),static_cast<Eigen::VectorXd::Index>(N));
            (void) K;  // dummy to suppress unused var warning

            stan::math::initialize(K, DUMMY_VAR__);
            stan::math::fill(K,DUMMY_VAR__);
            current_statement_begin__ = 25;
            validate_non_negative_index("mu", "N", N);
            Eigen::Matrix<T__,Eigen::Dynamic,1>  mu(static_cast<Eigen::VectorXd::Index>(N));
            (void) mu;  // dummy to suppress unused var warning

            stan::math::initialize(mu, DUMMY_VAR__);
            stan::math::fill(mu,DUMMY_VAR__);
            stan::math::assign(mu,rep_vector(0,N));
            current_statement_begin__ = 26;
            T__ moran_i;
            (void) moran_i;  // dummy to suppress unused var warning

            stan::math::initialize(moran_i, DUMMY_VAR__);
            stan::math::fill(moran_i,DUMMY_VAR__);
            current_statement_begin__ = 27;
            T__ avg_y;
            (void) avg_y;  // dummy to suppress unused var warning

            stan::math::initialize(avg_y, DUMMY_VAR__);
            stan::math::fill(avg_y,DUMMY_VAR__);
            stan::math::assign(avg_y,mean(y));
            current_statement_begin__ = 28;
            T__ sd_y;
            (void) sd_y;  // dummy to suppress unused var warning

            stan::math::initialize(sd_y, DUMMY_VAR__);
            stan::math::fill(sd_y,DUMMY_VAR__);
            stan::math::assign(sd_y,sd(y));
            current_statement_begin__ = 29;
            T__ cv_y;
            (void) cv_y;  // dummy to suppress unused var warning

            stan::math::initialize(cv_y, DUMMY_VAR__);
            stan::math::fill(cv_y,DUMMY_VAR__);
            stan::math::assign(cv_y,(avg_y / sd_y));


            {
            current_statement_begin__ = 31;
            T__ moran_i_num;
            (void) moran_i_num;  // dummy to suppress unused var warning

            stan::math::initialize(moran_i_num, DUMMY_VAR__);
            stan::math::fill(moran_i_num,DUMMY_VAR__);
            stan::math::assign(moran_i_num,0);
            current_statement_begin__ = 32;
            T__ moran_i_denom;
            (void) moran_i_denom;  // dummy to suppress unused var warning

            stan::math::initialize(moran_i_denom, DUMMY_VAR__);
            stan::math::fill(moran_i_denom,DUMMY_VAR__);
            stan::math::assign(moran_i_denom,0);


            current_statement_begin__ = 33;
            for (int i = 1; i <= NW; ++i) {

                current_statement_begin__ = 34;
                stan::math::assign(moran_i_num, (moran_i_num + ((get_base1(y,get_base1(get_base1(A,i,"A",1),1,"A",2),"y",1) - avg_y) * (get_base1(y,get_base1(get_base1(A,i,"A",1),2,"A",2),"y",1) - avg_y))));
            }
            current_statement_begin__ = 37;
            for (int i = 1; i <= N; ++i) {

                current_statement_begin__ = 38;
                stan::math::assign(moran_i_denom, (moran_i_denom + square((get_base1(y,i,"y",1) - avg_y))));
            }
            current_statement_begin__ = 40;
            stan::math::assign(moran_i, (moran_i_ratio * (moran_i_num / moran_i_denom)));
            }
            current_statement_begin__ = 43;
            for (int i = 1; i <= (N - 1); ++i) {

                current_statement_begin__ = 44;
                stan::math::assign(get_base1_lhs(K,i,i,"K",1), (1 + sigma));
                current_statement_begin__ = 45;
                for (int j = (i + 1); j <= N; ++j) {

                    current_statement_begin__ = 46;
                    stan::math::assign(get_base1_lhs(K,i,j,"K",1), exp((-(rho) * square(get_base1(D,i,j,"D",1)))));
                    current_statement_begin__ = 47;
                    stan::math::assign(get_base1_lhs(K,j,i,"K",1), get_base1(K,i,j,"K",1));
                }
            }
            current_statement_begin__ = 50;
            stan::math::assign(get_base1_lhs(K,N,N,"K",1), (1 + sigma));

            // validate transformed parameters
            for (int i0__ = 0; i0__ < N; ++i0__) {
                for (int i1__ = 0; i1__ < N; ++i1__) {
                    if (stan::math::is_uninitialized(K(i0__,i1__))) {
                        std::stringstream msg__;
                        msg__ << "Undefined transformed parameter: K" << '[' << i0__ << ']' << '[' << i1__ << ']';
                        throw std::runtime_error(msg__.str());
                    }
                }
            }
            for (int i0__ = 0; i0__ < N; ++i0__) {
                if (stan::math::is_uninitialized(mu(i0__))) {
                    std::stringstream msg__;
                    msg__ << "Undefined transformed parameter: mu" << '[' << i0__ << ']';
                    throw std::runtime_error(msg__.str());
                }
            }
            if (stan::math::is_uninitialized(moran_i)) {
                std::stringstream msg__;
                msg__ << "Undefined transformed parameter: moran_i";
                throw std::runtime_error(msg__.str());
            }
            if (stan::math::is_uninitialized(avg_y)) {
                std::stringstream msg__;
                msg__ << "Undefined transformed parameter: avg_y";
                throw std::runtime_error(msg__.str());
            }
            if (stan::math::is_uninitialized(sd_y)) {
                std::stringstream msg__;
                msg__ << "Undefined transformed parameter: sd_y";
                throw std::runtime_error(msg__.str());
            }
            if (stan::math::is_uninitialized(cv_y)) {
                std::stringstream msg__;
                msg__ << "Undefined transformed parameter: cv_y";
                throw std::runtime_error(msg__.str());
            }

            const char* function__ = "validate transformed params";
            (void) function__;  // dummy to suppress unused var warning
            current_statement_begin__ = 24;
            current_statement_begin__ = 25;
            current_statement_begin__ = 26;
            current_statement_begin__ = 27;
            current_statement_begin__ = 28;
            current_statement_begin__ = 29;

            // model body

            current_statement_begin__ = 57;
            lp_accum__.add(normal_log<propto__>(sigma, 0, 4));
            current_statement_begin__ = 58;
            lp_accum__.add(normal_log<propto__>(rho, 0, 5));
            current_statement_begin__ = 59;
            lp_accum__.add(multi_normal_log<propto__>(y, mu, K));
            current_statement_begin__ = 60;
            lp_accum__.add(normal_log<propto__>(avg_y, mean_p, mean_p_sd));
            current_statement_begin__ = 61;
            lp_accum__.add(normal_log<propto__>(moran_i, target_i, target_i_sd));

        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }

        lp_accum__.add(lp__);
        return lp_accum__.sum();

    } // log_prob()

    template <bool propto, bool jacobian, typename T_>
    T_ log_prob(Eigen::Matrix<T_,Eigen::Dynamic,1>& params_r,
               std::ostream* pstream = 0) const {
      std::vector<T_> vec_params_r;
      vec_params_r.reserve(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        vec_params_r.push_back(params_r(i));
      std::vector<int> vec_params_i;
      return log_prob<propto,jacobian,T_>(vec_params_r, vec_params_i, pstream);
    }


    void get_param_names(std::vector<std::string>& names__) const {
        names__.resize(0);
        names__.push_back("y");
        names__.push_back("sigma");
        names__.push_back("rho");
        names__.push_back("K");
        names__.push_back("mu");
        names__.push_back("moran_i");
        names__.push_back("avg_y");
        names__.push_back("sd_y");
        names__.push_back("cv_y");
    }


    void get_dims(std::vector<std::vector<size_t> >& dimss__) const {
        dimss__.resize(0);
        std::vector<size_t> dims__;
        dims__.resize(0);
        dims__.push_back(N);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(N);
        dims__.push_back(N);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dims__.push_back(N);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
        dims__.resize(0);
        dimss__.push_back(dims__);
    }

    template <typename RNG>
    void write_array(RNG& base_rng__,
                     std::vector<double>& params_r__,
                     std::vector<int>& params_i__,
                     std::vector<double>& vars__,
                     bool include_tparams__ = true,
                     bool include_gqs__ = true,
                     std::ostream* pstream__ = 0) const {
        vars__.resize(0);
        stan::io::reader<double> in__(params_r__,params_i__);
        static const char* function__ = "model_gpcor_namespace::write_array";
        (void) function__;  // dummy to suppress unused var warning
        // read-transform, write parameters
        vector_d y = in__.vector_lub_constrain(0,1,N);
        double sigma = in__.scalar_lb_constrain(0);
        double rho = in__.scalar_lb_constrain(0);
            for (int k_0__ = 0; k_0__ < N; ++k_0__) {
            vars__.push_back(y[k_0__]);
            }
        vars__.push_back(sigma);
        vars__.push_back(rho);

        if (!include_tparams__) return;
        // declare and define transformed parameters
        double lp__ = 0.0;
        (void) lp__;  // dummy to suppress unused var warning
        stan::math::accumulator<double> lp_accum__;

        double DUMMY_VAR__(std::numeric_limits<double>::quiet_NaN());
        (void) DUMMY_VAR__;  // suppress unused var warning

        try {
            current_statement_begin__ = 24;
            validate_non_negative_index("K", "N", N);
            validate_non_negative_index("K", "N", N);
            matrix_d K(static_cast<Eigen::VectorXd::Index>(N),static_cast<Eigen::VectorXd::Index>(N));
            (void) K;  // dummy to suppress unused var warning

            stan::math::initialize(K, std::numeric_limits<double>::quiet_NaN());
            stan::math::fill(K,DUMMY_VAR__);
            current_statement_begin__ = 25;
            validate_non_negative_index("mu", "N", N);
            vector_d mu(static_cast<Eigen::VectorXd::Index>(N));
            (void) mu;  // dummy to suppress unused var warning

            stan::math::initialize(mu, std::numeric_limits<double>::quiet_NaN());
            stan::math::fill(mu,DUMMY_VAR__);
            stan::math::assign(mu,rep_vector(0,N));
            current_statement_begin__ = 26;
            double moran_i(0.0);
            (void) moran_i;  // dummy to suppress unused var warning

            stan::math::initialize(moran_i, std::numeric_limits<double>::quiet_NaN());
            stan::math::fill(moran_i,DUMMY_VAR__);
            current_statement_begin__ = 27;
            double avg_y(0.0);
            (void) avg_y;  // dummy to suppress unused var warning

            stan::math::initialize(avg_y, std::numeric_limits<double>::quiet_NaN());
            stan::math::fill(avg_y,DUMMY_VAR__);
            stan::math::assign(avg_y,mean(y));
            current_statement_begin__ = 28;
            double sd_y(0.0);
            (void) sd_y;  // dummy to suppress unused var warning

            stan::math::initialize(sd_y, std::numeric_limits<double>::quiet_NaN());
            stan::math::fill(sd_y,DUMMY_VAR__);
            stan::math::assign(sd_y,sd(y));
            current_statement_begin__ = 29;
            double cv_y(0.0);
            (void) cv_y;  // dummy to suppress unused var warning

            stan::math::initialize(cv_y, std::numeric_limits<double>::quiet_NaN());
            stan::math::fill(cv_y,DUMMY_VAR__);
            stan::math::assign(cv_y,(avg_y / sd_y));


            {
            current_statement_begin__ = 31;
            double moran_i_num(0.0);
            (void) moran_i_num;  // dummy to suppress unused var warning

            stan::math::initialize(moran_i_num, std::numeric_limits<double>::quiet_NaN());
            stan::math::fill(moran_i_num,DUMMY_VAR__);
            stan::math::assign(moran_i_num,0);
            current_statement_begin__ = 32;
            double moran_i_denom(0.0);
            (void) moran_i_denom;  // dummy to suppress unused var warning

            stan::math::initialize(moran_i_denom, std::numeric_limits<double>::quiet_NaN());
            stan::math::fill(moran_i_denom,DUMMY_VAR__);
            stan::math::assign(moran_i_denom,0);


            current_statement_begin__ = 33;
            for (int i = 1; i <= NW; ++i) {

                current_statement_begin__ = 34;
                stan::math::assign(moran_i_num, (moran_i_num + ((get_base1(y,get_base1(get_base1(A,i,"A",1),1,"A",2),"y",1) - avg_y) * (get_base1(y,get_base1(get_base1(A,i,"A",1),2,"A",2),"y",1) - avg_y))));
            }
            current_statement_begin__ = 37;
            for (int i = 1; i <= N; ++i) {

                current_statement_begin__ = 38;
                stan::math::assign(moran_i_denom, (moran_i_denom + square((get_base1(y,i,"y",1) - avg_y))));
            }
            current_statement_begin__ = 40;
            stan::math::assign(moran_i, (moran_i_ratio * (moran_i_num / moran_i_denom)));
            }
            current_statement_begin__ = 43;
            for (int i = 1; i <= (N - 1); ++i) {

                current_statement_begin__ = 44;
                stan::math::assign(get_base1_lhs(K,i,i,"K",1), (1 + sigma));
                current_statement_begin__ = 45;
                for (int j = (i + 1); j <= N; ++j) {

                    current_statement_begin__ = 46;
                    stan::math::assign(get_base1_lhs(K,i,j,"K",1), exp((-(rho) * square(get_base1(D,i,j,"D",1)))));
                    current_statement_begin__ = 47;
                    stan::math::assign(get_base1_lhs(K,j,i,"K",1), get_base1(K,i,j,"K",1));
                }
            }
            current_statement_begin__ = 50;
            stan::math::assign(get_base1_lhs(K,N,N,"K",1), (1 + sigma));

            // validate transformed parameters
            current_statement_begin__ = 24;
            current_statement_begin__ = 25;
            current_statement_begin__ = 26;
            current_statement_begin__ = 27;
            current_statement_begin__ = 28;
            current_statement_begin__ = 29;

            // write transformed parameters
            for (int k_1__ = 0; k_1__ < N; ++k_1__) {
                for (int k_0__ = 0; k_0__ < N; ++k_0__) {
                vars__.push_back(K(k_0__, k_1__));
                }
            }
            for (int k_0__ = 0; k_0__ < N; ++k_0__) {
            vars__.push_back(mu[k_0__]);
            }
        vars__.push_back(moran_i);
        vars__.push_back(avg_y);
        vars__.push_back(sd_y);
        vars__.push_back(cv_y);

            if (!include_gqs__) return;
            // declare and define generated quantities



            // validate generated quantities

            // write generated quantities
        } catch (const std::exception& e) {
            stan::lang::rethrow_located(e, current_statement_begin__, prog_reader__());
            // Next line prevents compiler griping about no return
            throw std::runtime_error("*** IF YOU SEE THIS, PLEASE REPORT A BUG ***");
        }
    }

    template <typename RNG>
    void write_array(RNG& base_rng,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& params_r,
                     Eigen::Matrix<double,Eigen::Dynamic,1>& vars,
                     bool include_tparams = true,
                     bool include_gqs = true,
                     std::ostream* pstream = 0) const {
      std::vector<double> params_r_vec(params_r.size());
      for (int i = 0; i < params_r.size(); ++i)
        params_r_vec[i] = params_r(i);
      std::vector<double> vars_vec;
      std::vector<int> params_i_vec;
      write_array(base_rng,params_r_vec,params_i_vec,vars_vec,include_tparams,include_gqs,pstream);
      vars.resize(vars_vec.size());
      for (int i = 0; i < vars.size(); ++i)
        vars(i) = vars_vec[i];
    }

    static std::string model_name() {
        return "model_gpcor";
    }


    void constrained_param_names(std::vector<std::string>& param_names__,
                                 bool include_tparams__ = true,
                                 bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        for (int k_0__ = 1; k_0__ <= N; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "y" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }
        param_name_stream__.str(std::string());
        param_name_stream__ << "sigma";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "rho";
        param_names__.push_back(param_name_stream__.str());

        if (!include_gqs__ && !include_tparams__) return;
        for (int k_1__ = 1; k_1__ <= N; ++k_1__) {
            for (int k_0__ = 1; k_0__ <= N; ++k_0__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "K" << '.' << k_0__ << '.' << k_1__;
                param_names__.push_back(param_name_stream__.str());
            }
        }
        for (int k_0__ = 1; k_0__ <= N; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "mu" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }
        param_name_stream__.str(std::string());
        param_name_stream__ << "moran_i";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "avg_y";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "sd_y";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "cv_y";
        param_names__.push_back(param_name_stream__.str());

        if (!include_gqs__) return;
    }


    void unconstrained_param_names(std::vector<std::string>& param_names__,
                                   bool include_tparams__ = true,
                                   bool include_gqs__ = true) const {
        std::stringstream param_name_stream__;
        for (int k_0__ = 1; k_0__ <= N; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "y" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }
        param_name_stream__.str(std::string());
        param_name_stream__ << "sigma";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "rho";
        param_names__.push_back(param_name_stream__.str());

        if (!include_gqs__ && !include_tparams__) return;
        for (int k_1__ = 1; k_1__ <= N; ++k_1__) {
            for (int k_0__ = 1; k_0__ <= N; ++k_0__) {
                param_name_stream__.str(std::string());
                param_name_stream__ << "K" << '.' << k_0__ << '.' << k_1__;
                param_names__.push_back(param_name_stream__.str());
            }
        }
        for (int k_0__ = 1; k_0__ <= N; ++k_0__) {
            param_name_stream__.str(std::string());
            param_name_stream__ << "mu" << '.' << k_0__;
            param_names__.push_back(param_name_stream__.str());
        }
        param_name_stream__.str(std::string());
        param_name_stream__ << "moran_i";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "avg_y";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "sd_y";
        param_names__.push_back(param_name_stream__.str());
        param_name_stream__.str(std::string());
        param_name_stream__ << "cv_y";
        param_names__.push_back(param_name_stream__.str());

        if (!include_gqs__) return;
    }

}; // model

}

typedef model_gpcor_namespace::model_gpcor stan_model;


#endif
