#include <stddef.h>
#include <svm.h>

typedef struct svm_model svm_model_t;
typedef struct svm_node svm_node_t;
typedef struct svm_parameter svm_parameter_t;
typedef struct svm_problem svm_problem_t;

svm_node_t *nodes_new(size_t n);
void nodes_free(svm_node_t *nodes);
void nodes_put(svm_node_t *nodes, size_t node_idx, int idx,
  double value);

svm_parameter_t *parameter_new();

svm_problem_t *problem_new();
void problem_free(svm_problem_t *problem);
void problem_add_train_inst(svm_problem_t *problem, svm_node_t *nodes,
  double label);

int *labels_new(int n);
double *probs_new(svm_model_t *model);

// Can we do this directly in Go?
double get_double_idx(double *arr, int idx);
int get_int_idx(int *arr, int idx);

char const *svm_check_parameter_wrap(svm_problem_t *prob,
    svm_parameter_t *param);
int svm_check_probability_model_wrap(svm_model_t const *model);
void svm_get_labels_wrap(svm_model_t const *model, int *label);
void svm_destroy_param_wrap(svm_parameter_t* param);
svm_model_t *svm_load_model_wrap(char const *filename);
int svm_get_nr_class_wrap(svm_model_t const *model);
double svm_predict_probability_wrap(svm_model_t const *model, 
    svm_node_t const *x, double *prob_estimates);
double svm_predict_wrap(svm_model_t const *model, svm_node_t *nodes);
int svm_save_model_wrap(svm_model_t const *model, char const *filename);
svm_model_t *svm_train_wrap(svm_problem_t *prob, svm_parameter_t *param);
void svm_free_and_destroy_model_wrap(svm_model_t *model);
