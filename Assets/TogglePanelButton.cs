using UnityEngine;
using System.Collections;

public class TogglePanelButton : MonoBehaviour {
  public GameObject active;
  public GameObject suspended;
  public void TogglePanel (GameObject panel) {
      //panel.SetActive (!panel.activeSelf);
      if (panel.transform.parent == active.transform)
      {
        panel.transform.SetParent(suspended.transform);
      }
      else if (panel.transform.parent == suspended.transform)
      {
        panel.transform.SetParent(active.transform);
      }
    }
}
