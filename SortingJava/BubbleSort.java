public class Burbujeo {

	public static void burble(Integer[] arr) {
		Integer aux;
		for (int i = 0; i < arre.length - 1; i++) {
			for (int j = arr.length - 1; j > i; j--) {
				if (arr[j] < arr[j - 1]) {
					aux = arr[j];
					arr[j] = arr[j - 1];
					arr[j - 1] = aux;
				}
			}
		}
	}

}
