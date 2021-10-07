public class InsertionSort{

	public static void insertion (Integer arr[]) {
		int i, j;
		Integer aux;
		
		for (int k = arr.length - 1; k > 0; k--) {
			
		}
		for (i = 1; i < arr.length; i++) {
			aux = arr[i];
			j = i - 1;

			while ((j >= 0) && (arr[j] > aux)) {
				arr[j + 1] = arr[j];
				j--;
			}

			arr[j + 1] = aux;

		}
	}
