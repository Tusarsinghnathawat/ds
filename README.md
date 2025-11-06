1. R² Score (R-squared or Coefficient of Determination)
R² measures how well your model’s predictions match the real data.
It tells you how much of the variation in the target variable (Y) is explained by your model.
🧠 Formula (conceptually) R^2 = 1 - SSres/SStot​
SSres = Sum of squared differences between predictions and actual values (errors).
SStot = Total sum of squared differences between actual values and their mean.

2. RMSE (Root Mean Squared Error)
RMSE tells you how far off your predictions are from actual values, on average.
It’s the square root of the average of squared errors.

1️⃣ Confusion Matrix
It’s a table that shows how well your model’s predictions match the actual results.

	               Predicted: Spam	                  Predicted: Not Spam
Actual: Spam	✅ TP (True Positive)	❌ FN (False Negative)
Actual: Not Spam	❌ FP (False Positive)	✅ TN (True Negative)

2️⃣ Accuracy
Accuracy= TP+TN / TP+TN+FP+FN

3️⃣ Precision
Precision= TP/TP+FP
	​
4️⃣ Recall (Sensitivity or True Positive Rate)
👉 Of all actual positives, how many did the model correctly detect?
Recall=TP/TP+FN
	​
5️⃣ F1 Score
👉 The balance between precision and recall.
F1=2×(Precision×Recall/Precision+Recall)
