public class Selection {

	public static void selection(Integer[] arreglo) {
		int posMax;
		Integer aux;
		for (int i = arr.length - 1; i > 0; i--) { // start from last position
			posMax = 0;
			for (int j = 0; j <= i; j++) {
				if (arr[j] > arr[posMax])
					posMax = j;
			}
			aux = arr[i];
			arr[i] = arr[posMax];
			arr[posMax] = aux;
		}
	}
	
